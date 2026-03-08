#pragma once
#include "clsScreen.h"
#include "clsClient.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "FastWithdrawScreen.h"
#include "Withdraw.h"
#include "Deposite.h"
#include "CheackBalance.h"
#include "global.h"

class clsProcessesMenue : public clsScreen
{
private:


    enum enMainMenueOptions {
        FastWithdraw = 1, NormalWithdraw = 2, Deposite = 3,
        CheackBalance = 4, LogOut = 5
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = short(clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5? "));
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        Main_Menu_Screen();
    }

    static void _ShowFastWithdrawScreen()
    {
        FastWithdrawScreen::Quick_Withdraw_Menu_Screen();
    }

    static void _ShowNormalWithdrawScreen()
    {
        Withdraw::Normal_Withdraw_Menu_Screen();
    }

    static void _ShowDepositeScreen()
    {
        Deposite::Deposite_Screen();
    }

    static void _ShowCheackBalanceScreen()
    {
        CheackBalance::Cheack_Balance_Screen();
    }

    static void _ShowEndScreen()
    {
        CurrentClient = clsClient::_emptyclient();

    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::FastWithdraw:
        {
            system("cls");
            _ShowFastWithdrawScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::NormalWithdraw:
        {
            system("cls");
            _ShowNormalWithdrawScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::Deposite:
        {
            system("cls");
            _ShowDepositeScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::CheackBalance:
        {
            system("cls");
            _ShowCheackBalanceScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::LogOut:
        {
            system("cls");
            _ShowEndScreen();
            break;
        }
        }
    }

public:

    static void Main_Menu_Screen()
    {
        system("cls");
        _DrawScreenHeader("\t\tProcesses menu");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Fast Withdraw.\n";
        cout << setw(37) << left << "" << "\t[2] Normal Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Deposite.\n";
        cout << setw(37) << left << "" << "\t[4] Cheack Balance.\n";
        cout << setw(37) << left << "" << "\t[5] Log Out.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

