#ifndef CORE_OPTIONS_H
#define CORE_OPTIONS_H

#include "config.h"
#include "libretro.h"
#include "utils.h"
#include "replay.h"

typedef struct {
    const char* system;
    const char* monitor_type;
    int pi_family;
    int emu_quality;
    struct retro_variable cfgs[];
} cfg_core_mapping;

/* LCD */

const cfg_core_mapping lcd_amstrad_cpc =
{
    "amstrad_cpc", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"cap32_combokey", "b"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_arcade_fbneo =
{
    "arcade_fbneo", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"fbneo-diagnostic-input", "Hold Start + A + B"},
        {"fbneo-force-60hz", "enabled"},
        {"fbneo-allow-depth-32", "disabled"},
        {"fbneo-vertical-mode", "TATE"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_snk_ng =
{
    "snk_ng", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"fbneo-diagnostic-input", "Hold Start + A + B"},
        {"fbneo-force-60hz", "enabled"},
        {"fbneo-allow-depth-32", "disabled"},
        {"fbneo-vertical-mode", "TATE"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_snk_ngcd =
{
    "snk_ngcd", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"neocd_region", "USA"},
        {"neocd_bios", "neocd_z.rom (CDZ)"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_arcade_mame =
{
    "arcade_mame", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_arcade_mame_2k3p =
{
    "arcade_mame_2k3p", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"mame2003-plus_skip_disclaimer", "enabled"},
        {"mame2003-plus_skip_warnings", "enabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_commodore_c64 =
{
    "commodore_c64", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"vice_c64_model", "C64 NTSC auto"},
        {"vice_aspect_ratio", "raw"},
        {"vice_drive_true_emulation", "disabled"},
        {"vice_mapper_select", "TOGGLE_VKBD"},
        {"vice_mapper_b", "JOYSTICK_FIRE"},
        {"vice_mapper_a", "JOYSTICK_FIRE2"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_commodore_ami =
{
    "commodore_ami", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"puae_gfx_colors", "16bit"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_commodore_amicd =
{
    "commodore_amicd", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"puae_gfx_colors", "16bit"},
        {NULL, NULL}
    }
};

// Performance
const cfg_core_mapping lcd_sega_dc_pi5_low =
{
    "sega_dc", "lcd", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_LOW,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sega_dc_all_low =
{
    "sega_dc", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_LOW,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-strip (fast, least accurate)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

// Balanced
const cfg_core_mapping lcd_sega_dc_pi5_med =
{
    "sega_dc", "lcd", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sega_dc_all_med =
{
    "sega_dc", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-strip (fast, least accurate)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

// Quality
const cfg_core_mapping lcd_sega_dc_pi5_hi =
{
    "sega_dc", "lcd", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_HIGH,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "enabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sega_dc_all_hi =
{
    "sega_dc", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_HIGH,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

// Performance
const cfg_core_mapping lcd_arcade_dc_pi5_low =
{
    "arcade_dc", "lcd", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_LOW,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_arcade_dc_all_low =
{
    "arcade_dc", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_LOW,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-strip (fast, least accurate)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

// Balanced
const cfg_core_mapping lcd_arcade_dc_pi5_med =
{
    "arcade_dc", "lcd", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_arcade_dc_all_med =
{
    "arcade_dc", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-strip (fast, least accurate)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

// Quality
const cfg_core_mapping lcd_arcade_dc_pi5_hi =
{
    "arcade_dc", "lcd", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_HIGH,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "enabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_arcade_dc_all_hi =
{
    "arcade_dc", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_HIGH,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_nintendo_gb =
{
    "nintendo_gb", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"mgba_gb_model", "Game Boy"},
        {"mgba_gb_colors", "DMG Green"},
        {"mgba_skip_bios", "ON"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_nintendo_gbc =
{
    "nintendo_gbc", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"mgba_gb_model", "Game Boy Color"},
        {"mgba_skip_bios", "ON"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_nintendo_gba =
{
    "nintendo_gba", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"mgba_gb_model", "Game Boy Advance"},
        {"mgba_skip_bios", "ON"},
        {"mgba_force_gbp", "ON"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_nintendo_ds =
{
    "nintendo_ds", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"melonds_threaded_renderer", "enabled"},
        {"melonds_touch_mode", "Joystick"},
        {"melonds_screen_layout1", "rotate-right"},
        {"melonds_screen_layout2", "rotate-left"},
        {"melonds_screen_layout3", "top"},
        {"melonds_screen_layout4", "bottom"},
        {"melonds_screen_layout5", "top-bottom"},
        {"melonds_screen_layout6", "left-right"},
        {"melonds_screen_layout7", "bottom-top"},
        {"melonds_screen_layout8", "right-left"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sega_gg =
{
    "sega_gg", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"genesis_plus_gx_audio_filter", "low-pass"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sega_sms =
{
    "sega_sms", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sega_smd =
{
    "sega_smd", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"genesis_plus_gx_audio_filter", "low-pass"},
        {"genesis_plus_gx_render", "single field"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sega_cd =
{
    "sega_cd", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"genesis_plus_gx_audio_filter", "low-pass"},
        {"genesis_plus_gx_render", "single field"},
        {NULL, NULL}
    }
};

// Performance
const cfg_core_mapping lcd_nintendo_n64_all_low =
{
    "nintendo_n64", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_LOW,
    {
        /* LLE */
        //{"mupen64plus-rsp-plugin", "parallel"},
        //{"mupen64plus-rdp-plugin", "angrylion"},
        {"mupen64plus-angrylion-vioverlay", "Unfiltered"}, // Provides big performance boost
        {"mupen64plus-angrylion-multithread", "all threads"},
        /* HLE */
        {"mupen64plus-rsp-plugin", "hle"},
        {"mupen64plus-rdp-plugin", "gliden64"},
        {"mupen64plus-EnableNativeResFactor", "0"},
        {"mupen64plus-EnableOverscan", "Disabled"},
        {"mupen64plus-HybridFilter", "False"},
        {"mupen64plus-ThreadedRenderer", "True"},
        {"mupen64plus-43screensize", "320x240"},
        {"mupen64plus-169screensize", "640x360"},
        {"mupen64plus-GLideN64IniBehaviour", "disabled"},
        {"mupen64plus-EnableFBEmulation", "False"}, // Required for Mario Kart menu
        /* Generic */
        {"mupen64plus-pak1", "rumble"},
        {"mupen64plus-pak2", "memory"},
        {"mupen64plus-pak3", "memory"},
        {"mupen64plus-pak4", "memory"},
        {NULL, NULL}
    }
};

// Balanced
const cfg_core_mapping lcd_nintendo_n64_all_med =
{
    "nintendo_n64", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        /* LLE */
        //{"mupen64plus-rsp-plugin", "parallel"},
        //{"mupen64plus-rdp-plugin", "angrylion"},
        {"mupen64plus-angrylion-vioverlay", "Unfiltered"}, // Provides big performance boost
        {"mupen64plus-angrylion-multithread", "all threads"},
        /* HLE */
        {"mupen64plus-rsp-plugin", "hle"},
        {"mupen64plus-rdp-plugin", "gliden64"},
        {"mupen64plus-EnableNativeResFactor", "0"},
        {"mupen64plus-EnableOverscan", "Disabled"},
        {"mupen64plus-HybridFilter", "False"},
        {"mupen64plus-ThreadedRenderer", "True"},
        {"mupen64plus-43screensize", "320x240"},
        {"mupen64plus-169screensize", "640x360"},
        {"mupen64plus-GLideN64IniBehaviour", "disabled"},
        {"mupen64plus-EnableFBEmulation", "False"}, // Required for Mario Kart menu
        /* Generic */
        {"mupen64plus-pak1", "rumble"},
        {"mupen64plus-pak2", "memory"},
        {"mupen64plus-pak3", "memory"},
        {"mupen64plus-pak4", "memory"},
        {NULL, NULL}
    }
};

// Quality
const cfg_core_mapping lcd_nintendo_n64_pi5_hi =
{
    "nintendo_n64", "lcd", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_HIGH,
    {
        /* LLE */
        {"mupen64plus-rsp-plugin", "parallel"},
        {"mupen64plus-rdp-plugin", "angrylion"},
        {"mupen64plus-angrylion-vioverlay", "Unfiltered"}, // Provides big performance boost
        {"mupen64plus-angrylion-multithread", "all threads"},
        /* HLE */
        //{"mupen64plus-rsp-plugin", "hle"},
        //{"mupen64plus-rdp-plugin", "gliden64"},
        {"mupen64plus-EnableNativeResFactor", "0"},
        {"mupen64plus-EnableOverscan", "Disabled"},
        {"mupen64plus-HybridFilter", "False"},
        {"mupen64plus-ThreadedRenderer", "True"},
        {"mupen64plus-43screensize", "320x240"},
        {"mupen64plus-169screensize", "640x360"},
        {"mupen64plus-GLideN64IniBehaviour", "disabled"},
        {"mupen64plus-EnableFBEmulation", "True"}, // Required for Mario Kart menu
        /* Generic */
        {"mupen64plus-pak1", "rumble"},
        {"mupen64plus-pak2", "memory"},
        {"mupen64plus-pak3", "memory"},
        {"mupen64plus-pak4", "memory"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_nintendo_n64_all_hi =
{
    "nintendo_n64", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_HIGH,
    {
        /* LLE */
        //{"mupen64plus-rsp-plugin", "parallel"},
        //{"mupen64plus-rdp-plugin", "angrylion"},
        {"mupen64plus-angrylion-vioverlay", "Unfiltered"}, // Provides big performance boost
        {"mupen64plus-angrylion-multithread", "all threads"},
        /* HLE */
        {"mupen64plus-rsp-plugin", "hle"},
        {"mupen64plus-rdp-plugin", "gliden64"},
        {"mupen64plus-EnableNativeResFactor", "0"},
        {"mupen64plus-EnableOverscan", "Disabled"},
        {"mupen64plus-HybridFilter", "False"},
        {"mupen64plus-ThreadedRenderer", "True"},
        {"mupen64plus-43screensize", "320x240"},
        {"mupen64plus-169screensize", "640x360"},
        {"mupen64plus-GLideN64IniBehaviour", "disabled"},
        {"mupen64plus-EnableFBEmulation", "True"}, // Required for Mario Kart menu
        /* Generic */
        {"mupen64plus-pak1", "rumble"},
        {"mupen64plus-pak2", "memory"},
        {"mupen64plus-pak3", "memory"},
        {"mupen64plus-pak4", "memory"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_nintendo_nes =
{
    "nintendo_nes", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"fceumm_palette", "nes-classic-fbx-fs"},
        {"fceumm_show_crosshair", "enabled"},
        {"fceumm_zapper_tolerance", "10"},
        {"fceumm_overscan_h_left", "0"},
        {"fceumm_overscan_h_right", "0"},
        {"fceumm_overscan_v_top", "0"},
        {"fceumm_overscan_v_bottom", "0"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_ibm_pc =
{
    "ibm_pc", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"dosbox_pure_midi", "dosbox/MT32_CONTROL.ROM"},
        {"dosbox_pure_force60fps", "true"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_nec_pce =
{
    "nec_pce", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"pce_palette", "Composite"},
        {"pce_cddavolume", "150"},
        {"pce_cdspeed", "2"},
        {"pce_h_overscan", "disabled"},
        {"sgx_palette", "Composite"},
        {"sgx_cddavolume", "150"},
        {"sgx_cdspeed", "2"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_nec_pcecd =
{
    "nec_pcecd", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"pce_palette", "Composite"},
        {"pce_cddavolume", "150"},
        {"pce_cdspeed", "2"},
        {"pce_h_overscan", "disabled"},
        {"sgx_palette", "Composite"},
        {"sgx_cddavolume", "150"},
        {"sgx_cdspeed", "2"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sony_psx_pi3 =
{
    "sony_psx", "lcd", REPLAY_PI3_FAMILY, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"pcsx_rearmed_show_bios_bootlogo", "enabled"},
        {"pcsx_rearmed_vibration", "disabled"}, // Improves performance
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sony_psx_all =
{
    "sony_psx", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"swanstation_Display_CropMode", "Overscan"},
        {"swanstation_Display_ShowOSDMessages", "false"},
        {"swanstation_GPU_Renderer", "Software"},
        {"swanstation_Controller1_XScale", "0.90"},
        {"swanstation_Controller2_XScale", "0.90"},
        {"swanstation_Logging_LogLevel", "None"},
        {"swanstation_MemoryCards_Card2Type", "Shared"},
        {"swanstation_Hacks_OldMDECRoutines", "false"}, // Fixes https://github.com/libretro/swanstation/issues/127
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sega_32x =
{
    "sega_32x", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"picodrive_input1", "6 button pad"},
        {"picodrive_input2", "6 button pad"},
        {"picodrive_audio_filter", "low-pass"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_nintendo_snes =
{
    "nintendo_snes", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"snes9x_hires_blend", "merge"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sinclair_zx =
{
    "sinclair_zx", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"fuse_machine", "Spectrum 128K"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sharp_x68k =
{ /* https://github.com/libretro/px68k-libretro/wiki/Game-Notes---Video-Audio-modes-and-extra-functionality/
     https://retropie.org.uk/forum/topic/33298/playing-x68000-games-with-midi-music */
    "sharp_x68k", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"px68k_save_fdd_path", "disabled"},
        {"px68k_save_hdd_path", "disabled"},
        {"px68k_no_wait_mode", "enabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_panasonic_3do =
{
    "panasonic_3do", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"opera_bios", "panafz10.bin"},
        {"opera_dsp_threaded", "disabled"},
        {"opera_swi_hle", "enabled"},
        {"opera_font", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_philips_cdi =
{
    "philips_cdi", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"same_cdi_alternate_renderer", "enabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_atari_jaguar =
{
    "atari_jaguar", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"virtualjaguar_usefastblitter", "disabled"},
        {"virtualjaguar_doom_res_hack", "enabled"},
        {"virtualjaguar_alt_inputs", "enabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_atari_lynx =
{
    "atari_lynx", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"lynx_force_60hz", "enabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_atari_st =
{
    "atari_st", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"hatari_tosimage", "tos.img"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_scummvm =
{
    "scummvm", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"scummvm_frameskip_type", "disabled"},
        {"scummvm_video_hw_acceleration", "disabled"},
        {"scummvm_gui_aspect_ratio", "0"},
        {"scummvm_gui_h_res", "480"},
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_alpha_player =
{
    "alpha_player", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {NULL, NULL}
    }
};

const cfg_core_mapping lcd_sega_st =
{
    "sega_st", "lcd", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"beetle_saturn_virtuagun_crosshair", "On"},
        {NULL, NULL}
    }
};

/* CRT */

const cfg_core_mapping crt_amstrad_cpc =
{
    "amstrad_cpc", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"cap32_combokey", "b"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_arcade_fbneo =
{
    "arcade_fbneo", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"fbneo-diagnostic-input", "Hold Start + A + B"},
        {"fbneo-force-60hz", "disabled"},
        {"fbneo-allow-depth-32", "disabled"},
        {"fbneo-vertical-mode", "TATE"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_snk_ng =
{
    "snk_ng", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"fbneo-diagnostic-input", "Hold Start + A + B"},
        {"fbneo-force-60hz", "disabled"},
        {"fbneo-allow-depth-32", "disabled"},
        {"fbneo-vertical-mode", "TATE"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_snk_ngcd =
{
    "snk_ngcd", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"neocd_region", "USA"},
        {"neocd_bios", "neocd_z.rom (CDZ)"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_arcade_mame =
{
    "arcade_mame", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_arcade_mame_2k3p =
{
    "arcade_mame_2k3p", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"mame2003-plus_skip_disclaimer", "enabled"},
        {"mame2003-plus_skip_warnings", "enabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_commodore_c64 =
{
    "commodore_c64", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"vice_c64_model", "C64 NTSC auto"},
        {"vice_aspect_ratio", "raw"},
        {"vice_drive_true_emulation", "disabled"},
        {"vice_mapper_select", "TOGGLE_VKBD"},
        {"vice_mapper_b", "JOYSTICK_FIRE"},
        {"vice_mapper_a", "JOYSTICK_FIRE2"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_commodore_ami =
{
    "commodore_ami", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"puae_gfx_colors", "16bit"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_commodore_amicd =
{
    "commodore_amicd", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"puae_gfx_colors", "16bit"},
        {NULL, NULL}
    }
};

// Performance
const cfg_core_mapping crt_sega_dc_pi5_low =
{
    "sega_dc", "crt", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_LOW,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sega_dc_all_low =
{
    "sega_dc", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_LOW,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-strip (fast, least accurate)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

// Balanced
const cfg_core_mapping crt_sega_dc_pi5_med =
{
    "sega_dc", "crt", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sega_dc_all_med =
{
    "sega_dc", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-strip (fast, least accurate)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

// Quality
const cfg_core_mapping crt_sega_dc_pi5_hi =
{
    "sega_dc", "crt", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_HIGH,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "enabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sega_dc_all_hi =
{
    "sega_dc", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_HIGH,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

// Performance
const cfg_core_mapping crt_arcade_dc_pi5_low =
{
    "arcade_dc", "crt", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_LOW,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_arcade_dc_all_low =
{
    "arcade_dc", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_LOW,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-strip (fast, least accurate)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

// Balanced
const cfg_core_mapping crt_arcade_dc_pi5_med =
{
    "arcade_dc", "crt", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_arcade_dc_all_med =
{
    "arcade_dc", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-strip (fast, least accurate)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

// Quality
const cfg_core_mapping crt_arcade_dc_pi5_hi =
{
    "arcade_dc", "crt", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_HIGH,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "enabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_arcade_dc_all_hi =
{
    "arcade_dc", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_HIGH,
    {
        {"reicast_cable_type", "VGA"}, // Fixes interlazed video stability in CRT
        {"reicast_hle_bios", "disabled"},
        {"reicast_per_content_vmus", "VMU A1"},
        {"reicast_enable_dsp", "enabled"},
        {"reicast_threaded_rendering", "enabled"},
        {"reicast_anisotropic_filtering", "off"}, // Impact performance and makes text corruption in some games (Jet Set Radio, Ecco the Dolphin, Sonic Adventure 2)
        {"reicast_delay_frame_swapping", "disabled"},
        {"reicast_alpha_sorting", "per-triangle (normal)"}, // Affects Z-fighting
        {"reicast_emulate_framebuffer", "disabled"}, // Make mslug6 to run at 60 fps but causes performance and video issues
        {"reicast_detect_vsync_swap_interval", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_nintendo_gb =
{
    "nintendo_gb", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"mgba_gb_model", "Super Game Boy"},
        {"mgba_gb_colors", "DMG Green"},
        {"mgba_skip_bios", "ON"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_nintendo_gbc =
{
    "nintendo_gbc", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"mgba_gb_model", "Super Game Boy Color"},
        {"mgba_skip_bios", "ON"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_nintendo_gba =
{
    "nintendo_gba", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"mgba_gb_model", "Game Boy Advance"},
        {"mgba_skip_bios", "ON"},
        {"mgba_force_gbp", "ON"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_nintendo_ds =
{
    "nintendo_ds", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"melonds_threaded_renderer", "enabled"},
        {"melonds_touch_mode", "Joystick"},
        {"melonds_screen_layout1", "rotate-right"},
        {"melonds_screen_layout2", "rotate-left"},
        {"melonds_screen_layout3", "top"},
        {"melonds_screen_layout4", "bottom"},
        {"melonds_screen_layout5", "top-bottom"},
        {"melonds_screen_layout6", "left-right"},
        {"melonds_screen_layout7", "bottom-top"},
        {"melonds_screen_layout8", "right-left"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sega_gg =
{
    "sega_gg", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"genesis_plus_gx_audio_filter", "low-pass"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sega_sms =
{
    "sega_sms", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"genesis_plus_gx_overscan", "top/bottom"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sega_smd =
{
    "sega_smd", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"genesis_plus_gx_audio_filter", "low-pass"},
        {"genesis_plus_gx_render", "single field"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sega_cd =
{
    "sega_cd", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"genesis_plus_gx_audio_filter", "low-pass"},
        {"genesis_plus_gx_render", "single field"},
        {NULL, NULL}
    }
};

// Performance
const cfg_core_mapping crt_nintendo_n64_all_low =
{
    "nintendo_n64", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_LOW,
    {
        /* LLE */
        //{"mupen64plus-rsp-plugin", "parallel"},
        //{"mupen64plus-rdp-plugin", "angrylion"},
        {"mupen64plus-angrylion-vioverlay", "Unfiltered"}, // Provides big performance boost
        {"mupen64plus-angrylion-multithread", "all threads"},
        /* HLE */
        {"mupen64plus-rsp-plugin", "hle"},
        {"mupen64plus-rdp-plugin", "gliden64"},
        {"mupen64plus-EnableNativeResFactor", "0"},
        {"mupen64plus-EnableOverscan", "Disabled"},
        {"mupen64plus-HybridFilter", "False"},
        {"mupen64plus-ThreadedRenderer", "True"},
        {"mupen64plus-43screensize", "320x240"},
        {"mupen64plus-169screensize", "640x360"},
        {"mupen64plus-GLideN64IniBehaviour", "disabled"},
        {"mupen64plus-EnableFBEmulation", "False"}, // Required for Mario Kart menu
        /* Generic */
        {"mupen64plus-pak1", "rumble"},
        {"mupen64plus-pak2", "memory"},
        {"mupen64plus-pak3", "memory"},
        {"mupen64plus-pak4", "memory"},
        {NULL, NULL}
    }
};

// Balanced
const cfg_core_mapping crt_nintendo_n64_all_med =
{
    "nintendo_n64", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        /* LLE */
        //{"mupen64plus-rsp-plugin", "parallel"},
        //{"mupen64plus-rdp-plugin", "angrylion"},
        {"mupen64plus-angrylion-vioverlay", "Unfiltered"}, // Provides big performance boost
        {"mupen64plus-angrylion-multithread", "all threads"},
        /* HLE */
        {"mupen64plus-rsp-plugin", "hle"},
        {"mupen64plus-rdp-plugin", "gliden64"},
        {"mupen64plus-EnableNativeResFactor", "0"},
        {"mupen64plus-EnableOverscan", "Disabled"},
        {"mupen64plus-HybridFilter", "False"},
        {"mupen64plus-ThreadedRenderer", "True"},
        {"mupen64plus-43screensize", "320x240"},
        {"mupen64plus-169screensize", "640x360"},
        {"mupen64plus-GLideN64IniBehaviour", "disabled"},
        {"mupen64plus-EnableFBEmulation", "False"}, // Required for Mario Kart menu
        /* Generic */
        {"mupen64plus-pak1", "rumble"},
        {"mupen64plus-pak2", "memory"},
        {"mupen64plus-pak3", "memory"},
        {"mupen64plus-pak4", "memory"},
        {NULL, NULL}
    }
};

// Quality
const cfg_core_mapping crt_nintendo_n64_pi5_hi =
{
    "nintendo_n64", "crt", REPLAY_PI5_FAMILY, REPLAY_EMU_QUALITY_HIGH,
    {
        /* LLE */
        {"mupen64plus-rsp-plugin", "parallel"},
        {"mupen64plus-rdp-plugin", "angrylion"},
        {"mupen64plus-angrylion-vioverlay", "Unfiltered"}, // Provides big performance boost
        {"mupen64plus-angrylion-multithread", "all threads"},
        /* HLE */
        //{"mupen64plus-rsp-plugin", "hle"},
        //{"mupen64plus-rdp-plugin", "gliden64"},
        {"mupen64plus-EnableNativeResFactor", "0"},
        {"mupen64plus-EnableOverscan", "Disabled"},
        {"mupen64plus-HybridFilter", "False"},
        {"mupen64plus-ThreadedRenderer", "True"},
        {"mupen64plus-43screensize", "320x240"},
        {"mupen64plus-169screensize", "640x360"},
        {"mupen64plus-GLideN64IniBehaviour", "disabled"},
        {"mupen64plus-EnableFBEmulation", "True"}, // Required for Mario Kart menu
        /* Generic */
        {"mupen64plus-pak1", "rumble"},
        {"mupen64plus-pak2", "memory"},
        {"mupen64plus-pak3", "memory"},
        {"mupen64plus-pak4", "memory"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_nintendo_n64_all_hi =
{
    "nintendo_n64", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_HIGH,
    {
        /* LLE */
        //{"mupen64plus-rsp-plugin", "parallel"},
        //{"mupen64plus-rdp-plugin", "angrylion"},
        {"mupen64plus-angrylion-vioverlay", "Unfiltered"}, // Provides big performance boost
        {"mupen64plus-angrylion-multithread", "all threads"},
        /* HLE */
        {"mupen64plus-rsp-plugin", "hle"},
        {"mupen64plus-rdp-plugin", "gliden64"},
        {"mupen64plus-EnableNativeResFactor", "0"},
        {"mupen64plus-EnableOverscan", "Disabled"},
        {"mupen64plus-HybridFilter", "False"},
        {"mupen64plus-ThreadedRenderer", "True"},
        {"mupen64plus-43screensize", "320x240"},
        {"mupen64plus-169screensize", "640x360"},
        {"mupen64plus-GLideN64IniBehaviour", "disabled"},
        {"mupen64plus-EnableFBEmulation", "True"}, // Required for Mario Kart menu
        /* Generic */
        {"mupen64plus-pak1", "rumble"},
        {"mupen64plus-pak2", "memory"},
        {"mupen64plus-pak3", "memory"},
        {"mupen64plus-pak4", "memory"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_nintendo_nes =
{
    "nintendo_nes", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"fceumm_palette", "nes-classic-fbx-fs"},
        {"fceumm_show_crosshair", "disabled"},
        {"fceumm_zapper_tolerance", "10"},
        {"fceumm_overscan_h_left", "0"},
        {"fceumm_overscan_h_right", "0"},
        {"fceumm_overscan_v_top", "0"},
        {"fceumm_overscan_v_bottom", "0"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_ibm_pc =
{
    "ibm_pc", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"dosbox_pure_midi", "dosbox/MT32_CONTROL.ROM"},
        {"dosbox_pure_force60fps", "true"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_nec_pce =
{
    "nec_pce", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"pce_palette", "Composite"},
        {"pce_cddavolume", "150"},
        {"pce_cdspeed", "2"},
        {"pce_h_overscan", "disabled"},
        {"sgx_palette", "Composite"},
        {"sgx_cddavolume", "150"},
        {"sgx_cdspeed", "2"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_nec_pcecd =
{
    "nec_pcecd", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"pce_palette", "Composite"},
        {"pce_cddavolume", "150"},
        {"pce_cdspeed", "2"},
        {"pce_h_overscan", "disabled"},
        {"sgx_palette", "Composite"},
        {"sgx_cddavolume", "150"},
        {"sgx_cdspeed", "2"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sony_psx_pi3 =
{
    "sony_psx", "crt", REPLAY_PI3_FAMILY, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"pcsx_rearmed_show_bios_bootlogo", "enabled"},
        {"pcsx_rearmed_vibration", "disabled"}, // Improves performance
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sony_psx_all =
{
    "sony_psx", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"swanstation_Display_CropMode", "Overscan"},
        {"swanstation_Display_ShowOSDMessages", "false"},
        {"swanstation_GPU_Renderer", "Software"},
        {"swanstation_Controller1_XScale", "0.90"},
        {"swanstation_Controller2_XScale", "0.90"},
        {"swanstation_Logging_LogLevel", "None"},
        {"swanstation_MemoryCards_Card2Type", "Shared"},
        {"swanstation_Hacks_OldMDECRoutines", "false"}, // Fixes https://github.com/libretro/swanstation/issues/127
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sega_32x =
{
    "sega_32x", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"picodrive_input1", "6 button pad"},
        {"picodrive_input2", "6 button pad"},
        {"picodrive_audio_filter", "low-pass"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_nintendo_snes =
{
    "nintendo_snes", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"snes9x_hires_blend", "merge"},
        {"snes9x_superscope_crosshair", "0"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sinclair_zx =
{
    "sinclair_zx", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"fuse_machine", "Spectrum 128K"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sharp_x68k =
{ /* https://github.com/libretro/px68k-libretro/wiki/Game-Notes---Video-Audio-modes-and-extra-functionality/
     https://retropie.org.uk/forum/topic/33298/playing-x68000-games-with-midi-music */
    "sharp_x68k", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"px68k_save_fdd_path", "disabled"},
        {"px68k_save_hdd_path", "disabled"},
        {"px68k_no_wait_mode", "enabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_panasonic_3do =
{
    "panasonic_3do", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"opera_bios", "panafz10.bin"},
        {"opera_dsp_threaded", "disabled"},
        {"opera_swi_hle", "enabled"},
        {"opera_font", "disabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_philips_cdi =
{
    "philips_cdi", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"same_cdi_alternate_renderer", "enabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_atari_jaguar =
{
    "atari_jaguar", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"virtualjaguar_usefastblitter", "disabled"},
        {"virtualjaguar_doom_res_hack", "enabled"},
        {"virtualjaguar_alt_inputs", "enabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_atari_lynx =
{
    "atari_lynx", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"lynx_force_60hz", "enabled"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_atari_st =
{
    "atari_st", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"hatari_tosimage", "tos.img"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_scummvm =
{
    "scummvm", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"scummvm_frameskip_type", "disabled"},
        {"scummvm_video_hw_acceleration", "disabled"},
        {"scummvm_gui_aspect_ratio", "0"},
        {"scummvm_gui_h_res", "480"},
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_alpha_player =
{
    "alpha_player", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {NULL, NULL}
    }
};

const cfg_core_mapping crt_sega_st =
{
    "sega_st", "crt", REPLAY_PI_ALL, REPLAY_EMU_QUALITY_MEDIUM,
    {
        {"beetle_saturn_virtuagun_crosshair", "Off"},
        {NULL, NULL}
    }
};

const cfg_core_mapping* cfg_core_mappings[] = {
    &lcd_amstrad_cpc,
    &lcd_arcade_fbneo,
    &lcd_snk_ng,
    &lcd_snk_ngcd,
    &lcd_arcade_mame,
    &lcd_arcade_mame_2k3p,
    &lcd_commodore_c64,
    &lcd_commodore_ami,
    &lcd_commodore_amicd,
    &lcd_sega_dc_pi5_low,
    &lcd_sega_dc_all_low,
    &lcd_sega_dc_pi5_med,
    &lcd_sega_dc_all_med,
    &lcd_sega_dc_pi5_hi,
    &lcd_sega_dc_all_hi,
    &lcd_arcade_dc_pi5_low,
    &lcd_arcade_dc_all_low,
    &lcd_arcade_dc_pi5_med,
    &lcd_arcade_dc_all_med,
    &lcd_arcade_dc_pi5_hi,
    &lcd_arcade_dc_all_hi,
    &lcd_nintendo_gb,
    &lcd_nintendo_gbc,
    &lcd_nintendo_gba,
    &lcd_nintendo_ds,
    &lcd_sega_gg,
    &lcd_sega_smd,
    &lcd_sega_sms,
    &lcd_sega_cd,
    &lcd_sega_st,
    &lcd_nintendo_n64_all_low,
    &lcd_nintendo_n64_all_med,
    &lcd_nintendo_n64_pi5_hi,
    &lcd_nintendo_n64_all_hi,
    &lcd_nintendo_nes,
    &lcd_ibm_pc,
    &lcd_nec_pce,
    &lcd_nec_pcecd,
    &lcd_sony_psx_pi3,
    &lcd_sony_psx_all,
    &lcd_sega_32x,
    &lcd_nintendo_snes,
    &lcd_sinclair_zx,
    &lcd_sharp_x68k,
    &lcd_panasonic_3do,
    &lcd_philips_cdi,
    &lcd_atari_jaguar,
    &lcd_atari_lynx,
    &lcd_atari_st,
    &lcd_scummvm,
    &lcd_alpha_player,
    &crt_amstrad_cpc,
    &crt_arcade_fbneo,
    &crt_snk_ng,
    &crt_snk_ngcd,
    &crt_arcade_mame,
    &crt_arcade_mame_2k3p,
    &crt_commodore_c64,
    &crt_commodore_ami,
    &crt_commodore_amicd,
    &crt_sega_dc_pi5_low,
    &crt_sega_dc_all_low,
    &crt_sega_dc_pi5_med,
    &crt_sega_dc_all_med,
    &crt_sega_dc_pi5_hi,
    &crt_sega_dc_all_hi,
    &crt_arcade_dc_pi5_low,
    &crt_arcade_dc_all_low,
    &crt_arcade_dc_pi5_med,
    &crt_arcade_dc_all_med,
    &crt_arcade_dc_pi5_hi,
    &crt_arcade_dc_all_hi,
    &crt_nintendo_gb,
    &crt_nintendo_gbc,
    &crt_nintendo_gba,
    &crt_nintendo_ds,
    &crt_sega_gg,
    &crt_sega_smd,
    &crt_sega_sms,
    &crt_sega_cd,
    &crt_sega_st,
    &crt_nintendo_n64_all_low,
    &crt_nintendo_n64_all_med,
    &crt_nintendo_n64_pi5_hi,
    &crt_nintendo_n64_all_hi,
    &crt_nintendo_nes,
    &crt_ibm_pc,
    &crt_nec_pce,
    &crt_nec_pcecd,
    &crt_sony_psx_pi3,
    &crt_sony_psx_all,
    &crt_sega_32x,
    &crt_nintendo_snes,
    &crt_sinclair_zx,
    &crt_sharp_x68k,
    &crt_panasonic_3do,
    &crt_philips_cdi,
    &crt_atari_jaguar,
    &crt_atari_lynx,
    &crt_atari_st,
    &crt_scummvm,
    &crt_alpha_player,
    NULL
};

#endif