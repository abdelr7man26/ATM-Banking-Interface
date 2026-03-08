#pragma once
#include "global.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class Deposite :public clsScreen
{public:
    static void Deposite_Screen() {
        _DrawScreenHeader("\tdeposite");
        int amount = clsInputValidate::readInt("Enter amount to Deposite : ");
        CurrentClient.Deposit(amount);
        cout << amount << "deposited successfully";
    }

};

