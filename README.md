### Core-Option-Tester — a CLI probe for Libretro cores

Core-Option-Tester is a self-contained command-line utility that **loads any `*_libretro.so` core, negotiates the Libretro frontend API, and prints the core-option table in human-readable form**.
It is aimed at developers, packagers, and CI systems that need to QA or data-mine dozens of cores **without launching RetroArch** or wiring up a full frontend.

---

#### What the tool actually does

| Stage                                 | What happens                                                                                                                                                                                           | Why it matters                                                                                                         |
| ------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------------------------- |
| **1 · Dynamic loading**               | Uses *SDL2*’s portable `SDL_LoadObject/Function` wrappers to open a core and resolve every mandatory Libretro symbol (`retro_init`, `retro_run`, …).                                                   | Works on Linux, macOS, and Windows without `dlopen` / `LoadLibrary` ifdefs.                                            |
| **2 · Environment handshake**         | Implements the Libretro *environment callback* with stubs for every public constant (v0 → v2, experimental & private).                                                                                 | Guarantees that no core aborts because the frontend “lied” about a capability.                                         |
| **3 · Option negotiation**            | Reports an `OPTIONS_VERSION` of **0/1/2** (selectable on the command line) and captures the first `SET_CORE_OPTIONS[_V2[_INTL]]` call.                                                                 | Lets you see legacy v0 tables, modern v1 tables, or category-aware v2 tables exactly as the core exported them.        |
| **4 · Game-less init or sample load** | If the core supports `SET_SUPPORT_NO_GAME` it is initialised totally headless; otherwise small dummy ROM paths are supplied for arcade/console cores so they still reach their option code-path.       | Works even with cores that refuse to start without a “game”.                                                           |
| **5 · Bulk header validation**        | Reads every header inside `./check/` (e.g. `options_core.h`, `options_blacklist.h`, future additions) and cross-checks the keys against those the core just declared; duplicates are removed in-place. | One call validates *all* reference lists — no need to add extra `validate_core_options()` lines when new files appear. |
| **6 · Directory scan mode**           | Recurses over a directory, probes every core found, and prints only the option keys (one per line) for greppable batch processing.                                                                     | \~10× faster than launching RetroArch for each core when building distribution metadata.                               |

---

#### Typical usage

```bash
# Print the full v2 option block of a single core
./cot -f /path/to/genesis_plus_gx_libretro.so 2

# Query just one option from a v1 core
./cot -f snes9x_libretro.so 1 snes9x-overclock

# Scan a directory of cores, dump *only* option keys, and validate them
./cot -s /opt/retroarch/cores
```

---

#### Key features

* **Version-flexible** – speaks all three generations of the Core Options API.
* **Bit-mask aware** – correctly strips `EXPERIMENTAL` / `PRIVATE` bits so modern cores never mis-identify commands.
* **Safe stub library** – unimplemented environment queries return sane defaults instead of “true” lies that break cores.
* **Bulk validator** – a single pass reads every header in `./check/` and flags unknown or obsolete option keys.
* **Duplicate killer** – one in-memory pass removes repeated invalid keys before reporting totals.
* **Zero external deps** – aside from SDL2, it is pure ANSI C; no RetroArch sources required.
* **Helpful debug output** – compile with `-DDEBUG` to see every unknown environment call in real time.

---

#### Building

**IMPORTANT:** This core was only tested in Linux environment.

```bash
sudo apt install libsdl2-dev
make
```

(macOS: `brew install sdl2`; Windows: link against `SDL2.dll`.)

---

#### When would I use this?

* **CI/CD pipelines** – verify that every core in a nightly build still exports its option table.
* **Frontend development** – exercise a new Libretro UI without the complexity of an entire emulator.
* **Documentation scraping** – bulk-extract option keys/descriptions for automated README/GUI generation.
* **Regression hunting** – bisect which commit stopped a core from exposing an expected option.

---

#### Limitations

* Only the **option subsystem** is tested; audio/video callbacks are stubbed out.
* Requires a minimal ROM for cores that cannot boot with `NULL` (`fbneo`, some MAME forks, etc.).
* Directory scan mode assumes a filesystem/`readdir` that provides `d_type` (most POSIX systems do).
