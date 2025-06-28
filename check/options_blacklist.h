#ifndef OPTIONS_BLACKLIST_H
#define OPTIONS_BLACKLIST_H

#define BLACK_LIST_SIZE 250

#ifdef DEBUG
const char *options_black_list[BLACK_LIST_SIZE] = { NULL };
#else
const char *options_black_list[BLACK_LIST_SIZE] = {
	/* fbneo_libretro v2 */
	"fbneo-allow-depth-32",
	"frameskip",
	"cheat",
	/* mame2003_plus_libretro v2 */
	"mame2003-plus_frameskip",
	"cat_key_artwork",
	/* mamearcade_libretro v2 */
	"mame_cheats_enable",
	"mame_mame_paths_enable",
	"mame_autoloadfastforward",
	/* flycast_libretro v2 */
	"reicast_internal_resolution",
	"reicast_pvr2_filtering",
	"reicast_texupscale",
	"reicast_texupscale_max_filtered_texture_size",
	"reicast_auto_skip_frame",
	"reicast_frame_skipping",
	"reicast_widescreen_cheats",
	"reicast_widescreen_hack",
	"reicast_custom_textures",
	"reicast_dump_textures",
	"reicast_show_lightgun_settings",
	/* a5200_libretroa5200_libretro v2 */
	"a5200_mix_frames",
	/* genesis_plus_gx_libretro v2 */
	"genesis_plus_gx_aspect_ratio",
	"genesis_plus_gx_overscan",
	"genesis_plus_gx_left_border",
	"genesis_plus_gx_frameskip",
	"genesis_plus_gx_frameskip_threshold",
	"genesis_plus_gx_show_advanced_audio_settings",
	"genesis_plus_gx_no_sprite_limit",
	"genesis_plus_gx_enhanced_vscroll",
	"genesis_plus_gx_enhanced_vscroll_limit",
	"genesis_plus_gx_force_dtack",
	"genesis_plus_gx_addr_error",
	"genesis_plus_gx_blargg_ntsc_filter",
	/* virtualjaguar_libretro v2 */
	"virtualjaguar_alt_inputs",
	/* mednafen_lynx_libretro v2 */
	"lynx_pix_format",
	/* mednafen_pce_libretro v2 */
	"pce_show_advanced_input_settings",
	"pce_aspect_ratio",
	"pce_scaling",
	"pce_initial_scanline",
	"pce_last_scanline",
	"pce_h_overscan",
	"pce_hires_blend",
	/* fceumm_libretro v2 */
	"fceumm_aspect",
	"fceumm_overscan_h_left",
	"fceumm_overscan_h_right",
	"fceumm_overscan_v_bottom",
	"fceumm_overscan_v_top",
	"fceumm_show_adv_system_options",
	"fceumm_show_adv_sound_options",
	"fceumm_nospritelimit",
	"fceumm_ntsc_filter",
	/* snes9x_libretro v2 */
	"snes9x_aspect",
	"snes9x_overscan",
	"snes9x_show_advanced_av_settings",
	"snes9x_show_lightgun_settings",
	"snes9x_reduce_sprite_flicker",
	"snes9x_randomize_memory",
	"snes9x_block_invalid_vram_access",
	"snes9x_echo_buffer_hack",
	"snes9x_blargg",
	/* mupen64plus_next_libretro v2 */
	"mupen64plus-cpucore",
	"mupen64plus-CountPerOp",
	"mupen64plus-CountPerOpDenomPot",
	"mupen64plus-43screensize",
	"mupen64plus-169screensize",
	"mupen64plus-aspect",
	"mupen64plus-Framerate",
	"mupen64plus-EnableOverscan",
	"mupen64plus-OverscanTop",
	"mupen64plus-OverscanLeft",
	"mupen64plus-OverscanRight",
	"mupen64plus-OverscanBottom",
	"mupen64plus-GLideN64IniBehaviour",
	"mupen64plus-txCacheCompression",
	"mupen64plus-EnableNativeResFactor",
	"mupen64plus-EnableEnhancedTextureStorage",
	"mupen64plus-EnableEnhancedHighResStorage",
	"mupen64plus-txEnhancementMode",
	"mupen64plus-txHiresEnable",
	"mupen64plus-txHiresFullAlphaChannel",
	"mupen64plus-EnableHiResAltCRC",
	"mupen64plus-MaxHiResTxVramLimit",
	"mupen64plus-angrylion-overscan",
	"mupen64plus-angrylion-sync",
	"mupen64plus-FXAA",
	"mupen64plus-MultiSampling",
	/* mgba_libretro v2 */
	"mgba_frameskip",
	"mgba_frameskip_threshold",
	"mgba_frameskip_interval",
	/* melonds_libretro v2 */
	/* picodrive_libretro v2 */
	"picodrive_aspect",
	"picodrive_ggghost",
	"picodrive_frameskip",
	"picodrive_frameskip_threshold",
	/* mednafen_saturn_libretro v2 */
	"beetle_saturn_horizontal_overscan",
	"beetle_saturn_initial_scanline",
	"beetle_saturn_last_scanline",
	"beetle_saturn_initial_scanline_pal",
	"beetle_saturn_last_scanline_pal",
	/* flycast_libretro v2 */
	/* swanstation_libretro v2 */
	"swanstation_GPU_Renderer",
	"swanstation_GPU_TrueColor",
	"swanstation_Display_Force4_3For24Bit",
	"swanstation_GPU_ChromaSmoothing24Bit",
	"swanstation_GPU_UseSoftwareRendererForReadbacks",
	"swanstation_GPU_ResolutionScale",
	"swanstation_GPU_ScaledDithering",
	"swanstation_GPU_WidescreenHack",
	"swanstation_GPU_MSAA",
	"swanstation_GPU_TextureFilter",
	"swanstation_Display_AspectRatio",
	"swanstation_Display_CustomAspectRatioNumerator",
	"swanstation_Display_CustomAspectRatioDenominator",
	"swanstation_GPU_DownsampleMode",
	"swanstation_Display_ActiveStartOffset",
	"swanstation_Display_ActiveEndOffset",
	"swanstation_Display_LineStartOffset",
	"swanstation_Display_LineEndOffset",
	"swanstation_GPU_PGXPEnable",
	"swanstation_GPU_PGXPCulling",
	"swanstation_GPU_PGXPTextureCorrection",
	"swanstation_GPU_PGXPColorCorrection",
	"swanstation_GPU_PGXPDepthBuffer",
	"swanstation_GPU_PGXPVertexCache",
	"swanstation_GPU_PGXPCPU",
	"swanstation_GPU_PGXPPreserveProjFP",
	"swanstation_GPU_PGXPTolerance",
	"swanstation_GPU_PGXPDepthClearThreshold",
	//"swanstation_Display_CropMode", // Needed for fixing black screenin PSX PAL game (Silent Hill) by setting "Borders"
	/* vice_x64_libretro v2 */
	"vice_video_options_display",
	"vice_audio_options_display",
	"vice_mapping_options_display",
	"vice_aspect_ratio",
	"vice_crop",
	"vice_crop_mode",
	"vice_zoom_mode",
	"vice_zoom_mode_crop",
	"vice_manual_crop_top",
	"vice_manual_crop_bottom",
	"vice_manual_crop_left",
	"vice_manual_crop_right",
	"vice_mapper_crop_toggle",
	/* puae_libretro v2 */
	"puae_video_options_display",
	"puae_audio_options_display",
	"puae_mapping_options_display",
	"puae_video_aspect",
	"puae_video_resolution",
	"puae_video_vresolution",
	"puae_mapper_crop_toggle",
	"puae_crop",
	"puae_crop_delay",
	"puae_zoom_mode",
	"puae_crop_mode",
	"puae_zoom_mode_crop",
	"puae_vertical_pos",
	"puae_horizontal_pos",
	"puae_gfx_flickerfixer",
	"puae_gfx_framerate",
	"puae_gfx_colors",
	/* hatari_libretro v2 */
	"hatari_video_crop_overscan",
	"hatari_frameskips",
	/* dosbox_pure_libretro v2 */
	"dosbox_pure_aspect_correction",
	"dosbox_pure_overscan",
	/* scummvm_libretro v2 */
	"scummvm_frameskip_type",
	"scummvm_frameskip_threshold",
	"scummvm_frameskip_no",
	"scummvm_gui_aspect_ratio",
	"scummvm_gui_h_res",
	"scummvm_video_hw_acceleration",
	/* prosystem_libretro v1 */
	"prosystem_color_depth",
	/* opera_libretro v1 */
	"opera_vdlp_pixel_format",
	"opera_high_resolution",
	/* px68k_libretro v1 */
	"px68k_frameskip",
	/* stella_libretro v0 */
	"stella_crop_hoverscan",
	/* cap32_libretro v 0 */
	"cap32_gfx_colors",
	/* mednafen_ngp_libretro v0 */
	/* same_cdi_libretro v0 */
	"same_cdi_alternate_renderer",
	"same_cdi_altres",
	"same_cdi_boot_from_cli",
	"same_cdi_mame_paths_enable",
	/* bluemsx_libretro v0 */
	"bluemsx_overscan",
	/* fuse_libretro v0 */
	/* pcsx_rearmed_libretro v2 */
	"pcsx_rearmed_show_input_settings",
	"pcsx_rearmed_dithering",
	"pcsx_rearmed_frameskip_type",
	"pcsx_rearmed_frameskip_threshold",
	"pcsx_rearmed_frameskip_interval",
	"pcsx_rearmed_display_internal_fps",
	"pcsx_rearmed_screen_centering",
	"pcsx_rearmed_screen_centering_x",
	"pcsx_rearmed_screen_centering_y",
	"pcsx_rearmed_neon_enhancement_enable",
	"pcsx_rearmed_neon_enhancement_no_main",
	/* mednafen_supergrafx_libretro v2 */
	"sgx_aspect_ratio",
	"sgx_hoverscan",
	"sgx_initial_scanline",
	"sgx_last_scanline",
	/* snes9x2010_libretro v2 */
	"snes9x_2010_aspect",
	"snes9x_2010_frameskip",
	"snes9x_2010_frameskip_threshold",
	NULL
};
#endif
#endif