/* $Id: rev.cpp.in 27192 2015-03-17 20:33:44Z frosch $ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file rev.cpp Autogenerated file with the revision and such of OpenTTD. */

#include "stdafx.h"
#include "core/bitmath_func.hpp"
#include "rev.h"

#include "safeguards.h"

/**
 * Is this version of OpenTTD a release version?
 * @return True if it is a release version.
 */
bool IsReleasedVersion()
{
	return HasBit(_openttd_newgrf_version, 19);
}

/**
 * The text version of OpenTTD's revision.
 * This will be either "<major>.<minor>.<build>[-RC<rc>]",
 * "r<revision number>[M][-<branch>]" or "norev000".
 *
 * The major, minor and build are the numbers that describe releases of
 * OpenTTD (like 0.5.3). "-RC" is used to flag release candidates.
 *
 * The revision number is fairly straight forward. The M is to show that
 * the binary is made from modified source code. The branch shows the
 * branch the revision is of and will not be there when it is trunk.
 *
 * norev000 is for non-releases that are made on systems without
 * subversion or sources that are not a checkout of subversion.
 */
const char _openttd_revision[] = "norev000";

/**
 * The text version of OpenTTD's build date.
 * Updating the build date in this file is the safest as it generally gets
 * updated for each revision in contrary to most other files that only see
 * updates when they are actually changed themselves.
 */
const char _openttd_build_date[] = __DATE__ " " __TIME__;

/**
 * Let us know if current build was modified. This detection
 * works even in the case when revision string is overridden by
 * --revision argument.
 * Value 0 means no modification, 1 is for unknown state
 * (compiling from sources without any version control software)
 * and 2 is for modified revision.
 */
const byte _openttd_revision_modified = 1;

/**
 * The NewGRF revision of OTTD:
 * bits  meaning.
 * 28-31 major version
 * 24-27 minor version
 * 20-23 build
 *    19 1 if it is a release, 0 if it is not.
 *  0-18 revision number; 0 for releases and when the revision is unknown.
 *
 * The 19th bit is there so the development/betas/alpha, etc. leading to a
 * final release will always have a lower version number than the released
 * version, thus making comparisons on specific revisions easy.
 */
const uint32 _openttd_newgrf_version = 1 << 28 | 6 << 24 | 0 << 20 | 0 << 19 | (0 & ((1 << 19) - 1));

#ifdef __MORPHOS__
/**
 * Variable used by MorphOS to show the version.
 */
extern const char morphos_versions_tag[] = "$VER: OpenTTD norev000 (9.9.2016) OpenTTD Team [MorphOS, PowerPC]";
#endif