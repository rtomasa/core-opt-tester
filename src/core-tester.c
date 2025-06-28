#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <ctype.h>

#include "../include/core-option-tester.h"

#define MASK_ENV(cmd) ((cmd) & ~(RETRO_ENVIRONMENT_EXPERIMENTAL | RETRO_ENVIRONMENT_PRIVATE))

core_ctx_s core_ctx = {0};
int core_opt_ver = 0;
const char *requested_key = NULL;
bool options_printed = false;
bool print_full = false;
bool load_game = false;

/* Function name to pointer mapping for core symbols */
static const fn_links_s fn_links[] = {
	{"retro_init", (void **)&core_ctx.retro_init},
	{"retro_deinit", (void **)&core_ctx.retro_deinit},
	{"retro_api_version", (void **)&core_ctx.retro_api_version},
	{"retro_set_environment", (void **)&core_ctx.retro_set_environment},
	{"retro_set_video_refresh", (void **)&core_ctx.retro_set_video_refresh},
	{"retro_set_audio_sample", (void **)&core_ctx.retro_set_audio_sample},
	{"retro_set_audio_sample_batch", (void **)&core_ctx.retro_set_audio_sample_batch},
	{"retro_set_input_poll", (void **)&core_ctx.retro_set_input_poll},
	{"retro_set_input_state", (void **)&core_ctx.retro_set_input_state},
	{"retro_get_system_info", (void **)&core_ctx.retro_get_system_info},
	{"retro_get_system_av_info", (void **)&core_ctx.retro_get_system_av_info},
	{"retro_set_controller_port_device", (void **)&core_ctx.retro_set_controller_port_device},
	{"retro_reset", (void **)&core_ctx.retro_reset},
	{"retro_run", (void **)&core_ctx.retro_run},
	{"retro_serialize_size", (void **)&core_ctx.retro_serialize_size},
	{"retro_serialize", (void **)&core_ctx.retro_serialize},
	{"retro_unserialize", (void **)&core_ctx.retro_unserialize},
	{"retro_cheat_reset", (void **)&core_ctx.retro_cheat_reset},
	{"retro_cheat_set", (void **)&core_ctx.retro_cheat_set},
	{"retro_load_game", (void **)&core_ctx.retro_load_game},
	{"retro_load_game_special", (void **)&core_ctx.retro_load_game_special},
	{"retro_unload_game", (void **)&core_ctx.retro_unload_game},
	{"retro_get_region", (void **)&core_ctx.retro_get_region},
	{"retro_get_memory_data", (void **)&core_ctx.retro_get_memory_data},
	{"retro_get_memory_size", (void **)&core_ctx.retro_get_memory_size}};

static retro_time_t perf_get_time_usec(void) { return (retro_time_t)(0); }
static uint64_t perf_get_cpu_features(void) { return 0; }
static retro_perf_tick_t perf_get_perf_counter(void) { return 0; }
static void perf_noop_counter(struct retro_perf_counter *c) { (void)c; }
static void perf_noop(void) {}
static void frontend_log(enum retro_log_level level, const char *fmt, ...)
{
	(void)level;
	(void)*fmt;
}

#define MAX_CORE_OPTIONS 2048
static char *core_option_keys[MAX_CORE_OPTIONS];
static char *invalid_core_option_keys[MAX_CORE_OPTIONS];
static size_t core_option_count = 0;
static size_t invalid_core_option_count = 0;

static void remember_core_option(const char *key)
{
	if (!key || !*key)
		return;
	if (core_option_count >= MAX_CORE_OPTIONS)
		return;
	/* copy; lifespan extends beyond print_* scope */
	core_option_keys[core_option_count++] = strdup(key);
}

static void remember_invalid_core_option(const char *key)
{
	if (!key || !*key)
		return;
	if (invalid_core_option_count >= MAX_CORE_OPTIONS)
		return;
	/* copy; lifespan extends beyond print_* scope */
	invalid_core_option_keys[invalid_core_option_count++] = strdup(key);
}

static void dedup_invalid_core_option_keys(void)
{
	for (size_t i = 0; i < invalid_core_option_count; ++i)
	{
		const char *cur = invalid_core_option_keys[i];
		if (!cur)
			continue;

		/* compare with every subsequent element and remove duplicates */
		for (size_t j = i + 1; j < invalid_core_option_count;)
		{
			if (invalid_core_option_keys[j] &&
				strcmp(cur, invalid_core_option_keys[j]) == 0)
			{
				free(invalid_core_option_keys[j]);
				/* compact the array – shift everything after j left by 1 */
				memmove(&invalid_core_option_keys[j],
						&invalid_core_option_keys[j + 1],
						(invalid_core_option_count - j - 1) * sizeof(char *));
				--invalid_core_option_count;
				/* do NOT increment j – there is a new element at j now */
			}
			else
			{
				++j;
			}
		}
	}
}

static bool core_has_option(const char *key)
{
	for (size_t i = 0; i < core_option_count; ++i)
		if (strcmp(core_option_keys[i], key) == 0)
			return true;
	return false;
}

static void print_all_invalid_core_option_keys(void)
{
	for (size_t i = 0; i < invalid_core_option_count; ++i)
		if (invalid_core_option_keys[i])
			printf("%s\n", invalid_core_option_keys[i]);
	printf("Total: %ld\n", invalid_core_option_count);
}

static void validate_core_options_in_file(const char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    if (!fp)
    {
        fprintf(stderr, "[warn] cannot open %s - skipping\n", filepath);
        return;
    }

    char line[1024];
    while (fgets(line, sizeof line, fp))
    {
        /* locate first quote */
        char *p = strchr(line, '\"');
        if (!p)
            continue;
        char *q = strchr(p + 1, '\"');
        if (!q)
            continue;
        *q = '\0';
        const char *key = p + 1;

        /* ignore NULL entries or empty strings */
        while (*key && isspace((unsigned char)*key))
            ++key;
        if (!*key || strcmp(key, "NULL") == 0 || strstr(key, "_") == 0)
            continue;

        if (!core_has_option(key))
            remember_invalid_core_option(key);
    }
    fclose(fp);
}

static void validate_core_options(const char *dir_path)
{
    DIR *dir = opendir(dir_path);
    if (!dir)
    {
        fprintf(stderr, "[warn] cannot open directory %s - skipping validation\n",
                dir_path);
        return;
   }

    struct dirent *ent;
    char path[1024];

    while ((ent = readdir(dir)) != NULL)
    {
        if (ent->d_type != DT_REG && ent->d_type != DT_UNKNOWN)
            continue;                        /* only regular files */
        if (ent->d_name[0] == '.')           /* skip . and ..  */
            continue;

        snprintf(path, sizeof path, "%s/%s", dir_path, ent->d_name);
        validate_core_options_in_file(path);
    }
    closedir(dir);
}

static void print_quoted_or_null(const char *field)
{
	if (field && field[0])
		printf("\"%s\"", field);
	else
		printf("NULL");
}

static int print_options_v0(const struct retro_variable *data, const char *key)
{
	int found = 0, opt_num = 0;
	while (data[opt_num].key)
		opt_num++;
	if (!key)
		printf("Options number: %d\n", opt_num);

	for (int i = 0; data[i].key; i++)
	{
		if (!print_full)
		{
			remember_core_option(data[i].key);
			printf("%s\n", data[i].key);
		}
		else
		{
			if (key && strcmp(data[i].key, key) != 0)
				continue;
			found = 1;

			printf("{ \"%s\", \"%s\" },\n", data[i].key, data[i].value);
			if (key)
				break;
		}
	}
	return found;
}

static int print_options_v1(const struct retro_core_option_definition *data, const char *key)
{
	int found = 0, opt_num = 0;
	while (data[opt_num].key)
		opt_num++;
	if (!key)
		printf("Options number: %d\n", opt_num);

	for (int i = 0; data[i].key; i++)
	{
		if (!print_full)
		{
			printf("%s\n", data[i].key);
			remember_core_option(data[i].key);
		}
		else
		{
			if (key && strcmp(data[i].key, key) != 0)
				continue;
			found = 1;

			printf("{\n\t");
			print_quoted_or_null(data[i].key);
			printf(",\n\t");
			print_quoted_or_null(data[i].desc);
			printf(",\n\t");
			print_quoted_or_null(data[i].info);
			printf(",\n\t{\n");

			for (int j = 0; data[i].values[j].value; ++j)
			{
				printf("\t\t{ ");
				print_quoted_or_null(data[i].values[j].value);
				printf(", ");
				print_quoted_or_null(data[i].values[j].label);
				printf(" },\n");
			}
			printf("\t\t{ NULL, NULL }\n\t},\n\t");
			print_quoted_or_null(data[i].default_value);
			printf("\n},\n");

			if (key)
				break;
		}
	}
	return found;
}

static int print_options_v2(const struct retro_core_options_v2 *data, const char *key)
{
	if (!data || !data->definitions)
	{
		printf("No option definitions provided.\n");
		return 0;
	}

	int found = 0;
	const struct retro_core_option_v2_definition *def = data->definitions;

	if (print_full && !key && data->categories)
	{
		printf("Categories:\n");
		for (int i = 0; data->categories[i].key; i++)
		{
			const struct retro_core_option_v2_category *cat = &data->categories[i];
			printf("  { ");
			print_quoted_or_null(cat->key);
			printf(", ");
			print_quoted_or_null(cat->desc);
			printf(", ");
			print_quoted_or_null(cat->info);
			printf(" },\n");
		}
		printf("\n");
	}

	int opt_num = 0;
	while (def[opt_num].key)
		opt_num++;
	if (!key)
		printf("Options number: %d\n", opt_num);

	for (int i = 0; def[i].key; i++)
	{
		if (!print_full)
		{
			const struct retro_core_option_v2_definition *opt = &def[i];
			printf("%s\n", opt->key);
			remember_core_option(opt->key);
		}
		else
		{
			if (key && strcmp(def[i].key, key) != 0)
				continue;
			found = 1;
			const struct retro_core_option_v2_definition *opt = &def[i];
			printf("{\n\t");
			print_quoted_or_null(opt->key);
			printf(",\n\t");
			print_quoted_or_null(opt->desc);
			printf(",\n\t");
			print_quoted_or_null(opt->desc_categorized);
			printf(",\n\t");
			print_quoted_or_null(opt->info);
			printf(",\n\t");
			print_quoted_or_null(opt->info_categorized);
			printf(",\n\t");
			print_quoted_or_null(opt->category_key);
			printf(",\n\t{\n");

			for (int j = 0; opt->values[j].value; ++j)
			{
				printf("\t\t{ ");
				print_quoted_or_null(opt->values[j].value);
				printf(", ");
				print_quoted_or_null(opt->values[j].label);
				printf(" },\n");
			}
			printf("\t\t{ NULL, NULL }\n\t},\n\t");
			print_quoted_or_null(opt->default_value);
			printf("\n},\n");
			if (key)
				break;
		}
	}
	return found;
}

static bool core_environment(unsigned cmd, void *data)
{
	options_printed = false;

	switch (MASK_ENV(cmd))
	{
	case RETRO_ENVIRONMENT_GET_LANGUAGE:
	{
		*(unsigned *)data = RETRO_LANGUAGE_ENGLISH;
		break;
	}
	case RETRO_ENVIRONMENT_GET_LOG_INTERFACE:
	{
		struct retro_log_callback *cb = (struct retro_log_callback *)data;
		cb->log = frontend_log;
		return true;
	}
	break;
	case RETRO_ENVIRONMENT_GET_PERF_INTERFACE:
	{
		struct retro_perf_callback *cb = (struct retro_perf_callback *)data;
		cb->get_time_usec = perf_get_time_usec;
		cb->get_cpu_features = perf_get_cpu_features;
		cb->get_perf_counter = perf_get_perf_counter;
		cb->perf_register = perf_noop_counter;
		cb->perf_start = perf_noop_counter;
		cb->perf_stop = perf_noop_counter;
		cb->perf_log = perf_noop;
		break;
	}
	case RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY:
	case RETRO_ENVIRONMENT_GET_CORE_ASSETS_DIRECTORY:
	case RETRO_ENVIRONMENT_GET_SAVE_DIRECTORY:
	{
		const char **dir = (const char **)data;
		static const char *dummy_dir = "/tmp";
		*dir = dummy_dir;
		return true;
	}
	case RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION:
	{
		*(unsigned *)data = core_opt_ver;
		break;
	}
	case RETRO_ENVIRONMENT_SET_SUPPORT_NO_GAME:
	{
		const bool *support_no_game = data;
		if (support_no_game)
		{
			load_game = true;
		}
		break;
	}
	case RETRO_ENVIRONMENT_GET_VARIABLE:
		return false;
	case RETRO_ENVIRONMENT_GET_VARIABLE_UPDATE:
		if (data)
			*(bool *)data = true;
		return true;
	case RETRO_ENVIRONMENT_SET_VARIABLES: /* v0 */
		printf("Configuration API: v0\n");
		options_printed = true;
		if (!print_options_v0((const struct retro_variable *)data, requested_key))
			if (requested_key)
				printf("Option key '%s' not found.\n", requested_key);
		break;
	case RETRO_ENVIRONMENT_SET_CORE_OPTIONS_INTL: /* v1 */
		printf("Configuration API: v1 multilang\n");
		options_printed = true;
		{
			const struct retro_core_options_intl *intl_opt = data;
			if (intl_opt && intl_opt->us)
				data = intl_opt->us;
			else
				break;
		}
		// fall through
	case RETRO_ENVIRONMENT_SET_CORE_OPTIONS: /* v1 */
		printf("Configuration API: v1\n");
		options_printed = true;
		if (!print_options_v1((const struct retro_core_option_definition *)data, requested_key))
			if (requested_key)
				printf("Option key '%s' not found.\n", requested_key);
		break;
	case RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2_INTL: /* v2 */
		printf("Configuration API: v2 multilang\n");
		options_printed = true;
		{
			const struct retro_core_options_v2_intl *intl_opt = data;
			if (intl_opt && intl_opt->us)
				data = intl_opt->us;
			else
				break;
		}
		// fall through
	case RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2: /* v2 */
		printf("Configuration API: v2\n");
		options_printed = true;
		if (!print_options_v2((const struct retro_core_options_v2 *)data, requested_key))
			if (requested_key)
				printf("Option key '%s' not found.\n", requested_key);
		break;
	default:
#if DEBUG
		printf("Failed to execute RETRO_ENVIRONMENT %d\n", cmd);
#endif
		break;
	}
	return true;
}

static void core_load(const char *core_file)
{
	unsigned i;
	struct retro_system_info system;
	load_game = false;
	struct retro_game_info arcade_game_info = {
		.path = "./data/mk.zip",
		.data = NULL, // Explicitly set to NULL
		.size = 0,	  // Explicit initialization
		.meta = NULL  // Explicit initialization
	};
	struct retro_game_info fceumm_game_info = {
		.path = "./data/game.nes",
		.data = NULL, // Explicitly set to NULL
		.size = 0,	  // Explicit initialization
		.meta = NULL  // Explicit initialization
	};

	core_ctx.handle = SDL_LoadObject(core_file);

	if (!core_ctx.handle)
	{
		fprintf(stderr, "Error: failed loading core: %s\n", core_file);
		exit(EXIT_FAILURE);
	}

	/* Resolve all required symbols */
	for (i = 0; i < sizeof(fn_links) / sizeof(fn_links[0]); i++)
	{
		*fn_links[i].fn_ptr = SDL_LoadFunction(core_ctx.handle, fn_links[i].fn_str);
		if (*fn_links[i].fn_ptr == NULL)
		{
			fprintf(stderr, "Error: failed loading symbol: '%s'\n", fn_links[i].fn_str);
			SDL_UnloadObject(core_ctx.handle);
			core_ctx.handle = NULL;
			exit(EXIT_FAILURE);
		}
	}

	if (core_ctx.retro_api_version() != RETRO_API_VERSION)
	{
		fprintf(stderr, "Error: Incompatible Libretro API version (expected %d, got %d)\n",
				RETRO_API_VERSION, core_ctx.retro_api_version());
		SDL_UnloadObject(core_ctx.handle);
		core_ctx.handle = NULL;
		exit(EXIT_FAILURE);
	}

	memset(&system, 0, sizeof(system));
	core_ctx.retro_get_system_info(&system);

	printf("Core name: %s %s\n", system.library_name ? system.library_name : "unknown",
		   system.library_version ? system.library_version : "unknown");
	printf("Valid extensions: %s\n", system.valid_extensions ? system.valid_extensions : "(none)");

	core_ctx.retro_set_environment(core_environment);

	if (options_printed)
		return;

	core_ctx.retro_init();

	if (load_game)
	{
		core_ctx.retro_load_game(NULL);
		core_ctx.retro_unload_game();
	}
	else if (strstr(core_file, "fbneo") != 0 || strstr(core_file, "mame2003_plus") != 0)
	{
		core_ctx.retro_load_game(&arcade_game_info);
		core_ctx.retro_unload_game();
	}
	else if (strstr(core_file, "fceumm") != 0)
	{
		core_ctx.retro_load_game(&fceumm_game_info);
		core_ctx.retro_unload_game();
	}

	SDL_UnloadObject(core_ctx.handle);
	core_ctx.handle = NULL;
}

static int is_directory(const char *path)
{
	struct stat st;
	if (stat(path, &st) != 0)
		return 0;
	return S_ISDIR(st.st_mode);
}

static int is_core_file(const char *fname)
{
	const char *ext = "_libretro.so";
	size_t len = strlen(fname), extlen = strlen(ext);
	return len > extlen && strcmp(fname + len - extlen, ext) == 0;
}

static void process_core_file(const char *core_path, int opt_ver, const char *option_key)
{
	core_opt_ver = opt_ver;
	requested_key = option_key;
	core_load(core_path);
}

static void process_cores_in_dir(const char *dir_path, int opt_ver, const char *option_key)
{
	DIR *dir = opendir(dir_path);
	if (!dir)
	{
		fprintf(stderr, "Failed to open directory: %s\n", dir_path);
		exit(EXIT_FAILURE);
	}
	struct dirent *ent;
	char path[4096];
	int num_cores = 0;
	while ((ent = readdir(dir)) != NULL)
	{
		if (ent->d_type != DT_REG && ent->d_type != DT_LNK)
			continue;
		if (!is_core_file(ent->d_name))
			continue;
		snprintf(path, sizeof(path), "%s/%s", dir_path, ent->d_name);
		printf("\n==============================\n");
		printf("Processing core: %s\n", path);
		printf("==============================\n");
		process_core_file(path, opt_ver, option_key);
		num_cores++;
	}
	closedir(dir);

	printf("\n==============================\n");
	printf("Cores processed: %d\n", num_cores);
	printf("==============================\n");
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		goto usage;
	}

	if (strcmp(argv[1], "-f") == 0)
	{
		if (argc < 4)
			goto usage;

		const char *input_path = argv[2];
		int opt_ver = atoi(argv[3]);
		const char *option_key = (argc >= 5) ? argv[4] : NULL;

		printf("[%s] Compiled on %s, %s\n", "Core-Option-Tester v1.0.0", __DATE__, __TIME__);

		print_full = true;

		if (is_directory(input_path))
			process_cores_in_dir(input_path, opt_ver, option_key);
		else
			process_core_file(input_path, opt_ver, option_key);

		return EXIT_SUCCESS;
	}
	else if (strcmp(argv[1], "-s") == 0)
	{
		if (argc != 3)
			goto usage;

		const char *dir_path = argv[2];
		if (!is_directory(dir_path))
		{
			fprintf(stderr, "Error: path '%s' is not a directory.\n", dir_path);
			return EXIT_FAILURE;
		}
		print_full = false;
		process_cores_in_dir(dir_path, 2, NULL);
		validate_core_options("./check");
		dedup_invalid_core_option_keys();
		print_all_invalid_core_option_keys();
		return EXIT_SUCCESS;
	}

usage:
	fprintf(stderr, "Usage:\n");
	fprintf(stderr, "  %s -f <core|dir> <options_version> [option_key]\n", argv[0]);
	fprintf(stderr, "     - Print options structure\n");
	fprintf(stderr, "     <core|dir>        - Path to core .so or directory of cores\n");
	fprintf(stderr, "     <options_version> - Version number: 0, 1, or 2\n");
	fprintf(stderr, "     [option_key]      - (Optional) Option key to search and print\n");
	fprintf(stderr, "     Example: %s -f genesis_plus_gx_libretro.so 2 foo_option\n", argv[0]);
	fprintf(stderr, "     Example: %s -f /path/to/cores 2 foo_option\n", argv[0]);
	fprintf(stderr, "  %s -s <dir>\n", argv[0]);
	fprintf(stderr, "     - Print only option keys\n");
	fprintf(stderr, "     <dir>             - Path to directory of cores\n");
	fprintf(stderr, "     Example: %s -s /path/to/cores\n", argv[0]);
	return EXIT_FAILURE;
}
