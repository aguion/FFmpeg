/*
 * AC-3 encoder options
 * Copyright (c) 2011 Justin Ruggles <justin.ruggles@gmail.com>
 *
 * This file is part of Libav.
 *
 * Libav is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Libav is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Libav; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "libavutil/opt.h"
#include "ac3.h"

#if AC3ENC_TYPE == AC3ENC_TYPE_AC3_FIXED
static const AVOption ac3fixed_options[] = {
#elif AC3ENC_TYPE == AC3ENC_TYPE_AC3
static const AVOption ac3_options[] = {
#else /* AC3ENC_TYPE_EAC3 */
static const AVOption eac3_options[] = {
#endif
/* Metadata Options */
{"per_frame_metadata", "Allow Changing Metadata Per-Frame", OFFSET(allow_per_frame_metadata), FF_OPT_TYPE_INT, {.dbl = 0 }, 0, 1, AC3ENC_PARAM},
#if AC3ENC_TYPE != AC3ENC_TYPE_EAC3
/* AC-3 downmix levels */
{"center_mixlev", "Center Mix Level", OFFSET(center_mix_level), FF_OPT_TYPE_FLOAT, {.dbl = LEVEL_MINUS_4POINT5DB }, 0.0, 1.0, AC3ENC_PARAM},
{"surround_mixlev", "Surround Mix Level", OFFSET(surround_mix_level), FF_OPT_TYPE_FLOAT, {.dbl = LEVEL_MINUS_6DB }, 0.0, 1.0, AC3ENC_PARAM},
#endif
/* audio production information */
{"mixing_level", "Mixing Level", OFFSET(mixing_level), FF_OPT_TYPE_INT, {.dbl = -1 }, -1, 111, AC3ENC_PARAM},
{"room_type", "Room Type", OFFSET(room_type), FF_OPT_TYPE_INT, {.dbl = -1 }, -1, 2, AC3ENC_PARAM, "room_type"},
    {"notindicated", "Not Indicated (default)", 0, FF_OPT_TYPE_CONST, {.dbl = 0 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "room_type"},
    {"large",        "Large Room",              0, FF_OPT_TYPE_CONST, {.dbl = 1 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "room_type"},
    {"small",        "Small Room",              0, FF_OPT_TYPE_CONST, {.dbl = 2 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "room_type"},
/* other metadata options */
{"copyright", "Copyright Bit", OFFSET(copyright), FF_OPT_TYPE_INT, {.dbl = -1 }, -1, 1, AC3ENC_PARAM},
{"dialnorm", "Dialogue Level (dB)", OFFSET(dialogue_level), FF_OPT_TYPE_INT, {.dbl = -31 }, -31, -1, AC3ENC_PARAM},
{"dsur_mode", "Dolby Surround Mode", OFFSET(dolby_surround_mode), FF_OPT_TYPE_INT, {.dbl = -1 }, -1, 2, AC3ENC_PARAM, "dsur_mode"},
    {"notindicated", "Not Indicated (default)",    0, FF_OPT_TYPE_CONST, {.dbl = 0 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "dsur_mode"},
    {"on",           "Dolby Surround Encoded",     0, FF_OPT_TYPE_CONST, {.dbl = 1 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "dsur_mode"},
    {"off",          "Not Dolby Surround Encoded", 0, FF_OPT_TYPE_CONST, {.dbl = 2 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "dsur_mode"},
{"original", "Original Bit Stream", OFFSET(original), FF_OPT_TYPE_INT,   {.dbl = -1 }, -1, 1, AC3ENC_PARAM},
/* extended bitstream information */
{"dmix_mode", "Preferred Stereo Downmix Mode", OFFSET(preferred_stereo_downmix), FF_OPT_TYPE_INT, {.dbl = -1 }, -1, 2, AC3ENC_PARAM, "dmix_mode"},
    {"notindicated", "Not Indicated (default)", 0, FF_OPT_TYPE_CONST, {.dbl = 0 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "dmix_mode"},
    {"ltrt", "Lt/Rt Downmix Preferred",         0, FF_OPT_TYPE_CONST, {.dbl = 1 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "dmix_mode"},
    {"loro", "Lo/Ro Downmix Preferred",         0, FF_OPT_TYPE_CONST, {.dbl = 2 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "dmix_mode"},
{"ltrt_cmixlev", "Lt/Rt Center Mix Level", OFFSET(ltrt_center_mix_level), FF_OPT_TYPE_FLOAT, {.dbl = -1.0 }, -1.0, 2.0, AC3ENC_PARAM},
{"ltrt_surmixlev", "Lt/Rt Surround Mix Level", OFFSET(ltrt_surround_mix_level), FF_OPT_TYPE_FLOAT, {.dbl = -1.0 }, -1.0, 2.0, AC3ENC_PARAM},
{"loro_cmixlev", "Lo/Ro Center Mix Level", OFFSET(loro_center_mix_level), FF_OPT_TYPE_FLOAT, {.dbl = -1.0 }, -1.0, 2.0, AC3ENC_PARAM},
{"loro_surmixlev", "Lo/Ro Surround Mix Level", OFFSET(loro_surround_mix_level), FF_OPT_TYPE_FLOAT, {.dbl = -1.0 }, -1.0, 2.0, AC3ENC_PARAM},
{"dsurex_mode", "Dolby Surround EX Mode", OFFSET(dolby_surround_ex_mode), FF_OPT_TYPE_INT, {.dbl = -1 }, -1, 2, AC3ENC_PARAM, "dsurex_mode"},
    {"notindicated", "Not Indicated (default)",       0, FF_OPT_TYPE_CONST, {.dbl = 0 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "dsurex_mode"},
    {"on",           "Dolby Surround EX Encoded",     0, FF_OPT_TYPE_CONST, {.dbl = 1 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "dsurex_mode"},
    {"off",          "Not Dolby Surround EX Encoded", 0, FF_OPT_TYPE_CONST, {.dbl = 2 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "dsurex_mode"},
{"dheadphone_mode", "Dolby Headphone Mode", OFFSET(dolby_headphone_mode), FF_OPT_TYPE_INT, {.dbl = -1 }, -1, 2, AC3ENC_PARAM, "dheadphone_mode"},
    {"notindicated", "Not Indicated (default)",     0, FF_OPT_TYPE_CONST, {.dbl = 0 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "dheadphone_mode"},
    {"on",           "Dolby Headphone Encoded",     0, FF_OPT_TYPE_CONST, {.dbl = 1 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "dheadphone_mode"},
    {"off",          "Not Dolby Headphone Encoded", 0, FF_OPT_TYPE_CONST, {.dbl = 2 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "dheadphone_mode"},
{"ad_conv_type", "A/D Converter Type", OFFSET(ad_converter_type), FF_OPT_TYPE_INT, {.dbl = -1 }, -1, 1, AC3ENC_PARAM, "ad_conv_type"},
    {"standard", "Standard (default)", 0, FF_OPT_TYPE_CONST, {.dbl = 0 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "ad_conv_type"},
    {"hdcd",     "HDCD",               0, FF_OPT_TYPE_CONST, {.dbl = 1 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "ad_conv_type"},
/* Other Encoding Options */
{"stereo_rematrixing", "Stereo Rematrixing", OFFSET(stereo_rematrixing), FF_OPT_TYPE_INT, {.dbl = 1 }, 0, 1, AC3ENC_PARAM},
#if AC3ENC_TYPE != AC3ENC_TYPE_AC3_FIXED
{"channel_coupling",   "Channel Coupling",   OFFSET(channel_coupling),   FF_OPT_TYPE_INT, {.dbl = 1 }, 0, 1, AC3ENC_PARAM, "channel_coupling"},
    {"auto", "Selected by the Encoder", 0, FF_OPT_TYPE_CONST, {.dbl = -1 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "channel_coupling"},
{"cpl_start_band", "Coupling Start Band", OFFSET(cpl_start), FF_OPT_TYPE_INT, {.dbl = -1 }, -1, 15, AC3ENC_PARAM, "cpl_start_band"},
    {"auto", "Selected by the Encoder", 0, FF_OPT_TYPE_CONST, {.dbl = -1 }, INT_MIN, INT_MAX, AC3ENC_PARAM, "cpl_start_band"},
#endif
{NULL}
};
