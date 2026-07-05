# Setup Checker

Setup Checker is a Windows console utility that runs a pre-flight system check for a CL client setup. It must be run as administrator because several checks read or change machine-wide Windows settings.

The tool prints results to the console, records structured check results internally, can export results as JSON, and marks when a restart is required for changes to take effect.

By default, Setup Checker runs in two stages:

1. It checks the system and displays the current results without applying changes.
2. If changes are needed, it asks for permission with a yes/no prompt before applying them.

## What It Checks

- Windows Defender service and tamper-protection status
- Third-party antivirus detection
- Secure Boot status
- CPU virtualization status
- Riot Vanguard installation status
- Microsoft Visual C++ Redistributable installation
- Google Chrome installation and Chrome Safe Browsing policy
- Windows time service sync
- Windows version support
- `C:\Symbols` cleanup status
- Fast Boot status
- Exploit Protection policy
- SmartScreen policy
- Xbox Game Bar setting
- TPM status
- Core Isolation / HVCI and VBS status
- Kernel DMA Protection status
- Modified/custom Windows build indicators
- Internet connectivity and basic repair attempts
- Network adapter inventory with `USED` / `NOT USED` status
- Virtual machine indicators
- GitHub release update status, checked weekly and cached locally
- Security mitigation status for VBS, HVCI, KVA shadowing, and Hyper-V

## Changes It May Apply

Depending on the current system state, the checker may attempt to:

- Disable Windows Defender policy/service settings
- Disable Chrome Safe Browsing policy
- Sync and repair Windows Time service registration
- Delete `C:\Symbols`
- Disable Fast Boot
- Disable Exploit Protection override policy
- Disable SmartScreen
- Enable Xbox Game Bar capture setting
- Disable HVCI / VBS registry settings
- Set Device Guard and HVCI lock values used by this setup
- Disable KVA shadowing CPU mitigation settings
- Set `hypervisorlaunchtype` to `off`
- Disable Hyper-V optional features
- Flush DNS, reset Winsock, and renew IP configuration during internet repair
- Download and install VC Redist if missing

The tool does not force an automatic reboot, but it will show when a restart is required.

## CLI Usage

```text
CL-Setup.exe [options]
```

Options:

```text
--help              Show help
--headless          Run without user interaction
--quiet             Only show errors and warnings
--apply             Apply needed changes without prompting
--export FILE       Export results as JSON
--skip N[,M,...]    Skip specific checks by number
--only N[,M,...]    Run only specific checks by number
```

Check numbers:

```text
1=WindowsDefender 2=3rdPartyAV 3=SecureBoot 4=CPU-V 5=RiotVanguard
6=VCRedist 7=Chrome 8=ChromeProtection 9=TimeSync 10=Winver
11=Symbols 12=FastBoot 13=ExploitProtection 14=SmartScreen
15=GameBar 16=TPM 17=CoreIsolation 18=DMAProtection 19=ModifiedOS
20=Internet 21=NetworkAdapters 22=VM-Detect 23=Auto-Update
24=SecurityMitigations
```

## Build

Open `CL Setup.sln` in Visual Studio 2022 and build for `Release|x64` or `Release|Win32`.

The project targets C++20 and requires administrator privileges at runtime.

## Credits

Original creator: coby69 (Coby)  
Maintained by: Julien-winter  

This project is released under the GNU General Public License (GPL). See http://www.gnu.org/licenses/gpl-3.0.txt for more information.
