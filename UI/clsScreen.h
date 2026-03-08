#pragma once
#include <iostream>
#include "global.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";
        if (!CurrentClient.isEmpty()) {
            cout << "\n\t\t\t\t\t  ACC:" << CurrentClient.AccountNumber() << " | ACC.Holder " << CurrentClient.firstName << " | Balance: " << CurrentClient.accountBalance;
            cout << "\n\t\t\t\t\t______________________________________\n";

        }
    }

};

