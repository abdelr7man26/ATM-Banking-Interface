#pragma once
#include "global.h"
#include "clsInputValidate.h"

#include "clsScreen.h"

class Withdraw :public clsScreen
{
public:

    static void Normal_Withdraw_Menu_Screen() {
        _DrawScreenHeader("\tWithdraw");
        int amount = clsInputValidate::readInt("Enter amount to Withdraw : ");
        if (CurrentClient.Withdraw(amount)) { cout << amount << "withdrawed successfully"; }
        else cout << "no enough balance in your account";
      
    }
};

