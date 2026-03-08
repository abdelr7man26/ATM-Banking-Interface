#pragma once
#include "global.h"
#include "clsScreen.h"
class CheackBalance : public clsScreen
{
public:
    static void Cheack_Balance_Screen() {
        clsScreen::_DrawScreenHeader("\tcheack balance");
        cout << "Your Balance is : " << CurrentClient.accountBalance;
    }

};

