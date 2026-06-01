# CL-Setup

**Original Creator:** coby69 (Coby)  
**Maintained by:** Julien-winter

This code is released under the GNU General Public License (GPL).
See http://www.gnu.org/licenses/gpl-3.0.txt for more information.

The purpose of this program is to help the user setup the CL Client by doing all the things that you used to have do yourself, automatically.

## Changes & Bug Fixes

- Added async VCRedist installation (non-blocking thread)
- Added additional checks: GameBar, Modified OS detection, TPM status, Core Isolation (HVCI), DMA Protection
- Improved Winver check with Windows 11 23H2 / 24H2 support
- Improved Windows Defender check (service-based instead of registry)
- Better error handling with detailed error codes
- Improved build settings: C++20, static linking, admin rights
- Various bug fixes and stability improvements

## Build

Open `CL Setup.sln` in Visual Studio 2022 and build for Release|x64 or Release|Win32.
