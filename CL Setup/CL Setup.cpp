// Original creator: Coby (coby69) - thanks Kali for the read DWORD function
// Bug fixes and improvements by: Julien-winter
// This version was made on 17/08/2023 (DD/MM/YYYY).
// This is an open-source project and any and all code can be modified at any point in time.

// Copyright 2023 CheatLoverz.store
//
// This code is released under the GNU General Public License (GPL).
// See https://www.gnu.org/licenses/gpl-3.0.txt for more information.

#include "Includes.h"

int main()
{
    // Run the console settings setup
    Helper::setupConsole();

    // Send a message informing the user of how long it will take
    Color::setForegroundColor(Color::Cyan);
    std::cout << "Please wait 1-2 minutes while we run through and check everything\n";
    Color::setForegroundColor(Color::Green);
    std::cout << "Wait till the program says to take a screenshot to send one\n";
    Color::setForegroundColor(Color::LightGray);
    std::cout << "-----------------------------------------------------------------\n";

    // Small sleep function so the user doesn't feel overwhelmed when first opening the program
    Sleep(1500);
    
    //Run through all the checks
    Checks::checkWindowsDefender();
    Checks::check3rdPartyAntiVirus();
    Checks::checkSecureBoot();
    Checks::checkCPUV();
    Checks::uninstallRiotVanguard();
    std::thread vcThread(Checks::installVCRedist);
    while (Helper::vcComplete == false)
    {
        Sleep(10);
        Helper::vcCheckSleepTimes = Helper::vcCheckSleepTimes + 10;

        if (Helper::vcCheckSleepTimes >= 30000)
        {
            Helper::printConcern("- VCRedist is taking too long, continuing without waiting (still downloading)");
            break;
        }
    }
    Checks::isChromeInstalled();
    Checks::disableChromeProtection();
    Checks::syncWindowsTime();

    // Add a message informing the user we are running additional checks
    Color::setForegroundColor(Color::LightGray);
    std::cout << "-----------------------------------------------------------------\n";
    Color::setForegroundColor(Color::Cyan);
    std::cout << "Successfully ran standard checks, now running additional checks\n";
    Color::setForegroundColor(Color::LightGray);
    std::cout << "-----------------------------------------------------------------\n";

    // Run additional checks
    Checks::checkWinver();
    Checks::deleteSymbols();
    Checks::checkFastBoot();
    Checks::checkExploitProtection();
    Checks::checkSmartScreen();
    Checks::checkGameBar();
    Checks::checkTPMStatus();
    Checks::checkCoreIsolation();
    Checks::checkDMAProtection();
    Checks::checkModifiedOS();

    if (Helper::vcComplete == false)
    {
        SetConsoleTitleA("Still waiting for VCRedist");
        while (Helper::vcComplete == false)
        {
            Sleep(10);
            Helper::vcCheckSleepTimes = Helper::vcCheckSleepTimes + 10;

            if (Helper::vcCheckSleepTimes >= 60000)
            {
                Helper::printConcern("- VCRedist is taking very long, restart program and try again (or wait)");
                break;
            }
        }
    }

    // Seperate and notify user of additional checks
    Color::setForegroundColor(Color::LightGray);
    std::cout << "-----------------------------------------------------------------\n";
    Color::setForegroundColor(Color::Cyan);
    std::cout << "Successfully ran additional checks, feel free to close the application\n";
    Color::setForegroundColor(Color::Green);
    std::cout << "Please take a screenshot of the program now and send it support";
    if (Helper::restartRequired)
    {
        Color::setForegroundColor(Color::Red);
        std::cout << "\n(Restart required to apply all changes)";
    }

    std::cout << "\n";
    SetConsoleTitleA("Checking completed!");

    Sleep(100);
    vcThread.join();

    // Hang the application
    SetConsoleTitleA("Checking completed!");
    Sleep(-1);
}