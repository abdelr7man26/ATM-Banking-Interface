#pragma once
#include "clsClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "global.h"

class FastWithdrawScreen : public clsScreen
{
private:
    static int Quick_Withdraw_Menu_Screen_Functions() {
        short process = static_cast<short>(clsInputValidate::ReadIntNumberBetween(1, 7, "choose a process (1,2,3,4,5,6,7): "));
      
        switch (process) {
        case 1:
            return 50;
        case 2:
            return 100;
        case 3:
            return 200;
        case 4:
            return 500;
        case 5:
            return 1000;

        case 6:
            return 5000;
        case 7:
            return 0;
        }
    }

public:
    static void Quick_Withdraw_Menu_Screen() {
        _DrawScreenHeader("\tWithdraw");
        cout << "\t\t[1] 50              [2] 100\n";
        cout << "\t\t[3] 200             [4] 500\n";
        cout << "\t\t[5] 1000            [6] 5000\n";
        cout << "\t\t[7] Canceled" << endl;
        int amount = Quick_Withdraw_Menu_Screen_Functions();
        if (amount == 0) return;
        if (CurrentClient.Withdraw(amount) ) { cout << amount << "withdrawed successfully"; }
        else cout << "cancelled";
    }

};

