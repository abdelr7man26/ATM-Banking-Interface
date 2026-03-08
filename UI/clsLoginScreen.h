#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClient.h"
#include "clsProcessesMenue.h"
class clsLoginScreen : public clsScreen
{
private:
    static  bool _Login()
    {
        bool LoginFaild = false;

        short tries = 0;

        string AccountNumber, Password;
        do
        {
            if (tries == 3)
            {
                cout << "you are out of tries.";
                return false;
            }

            if (LoginFaild)
            {
                cout << "\nInvlaid account Number/Password!\n\n";


            }

            cout << "Enter Account Number? ";
            cin >> AccountNumber;
            cin.ignore();
            cout << "Enter Password? ";
            cin >> Password;
            cin.ignore();

             CurrentClient = clsClient::find(AccountNumber, Password);

            LoginFaild = CurrentClient.isEmpty();
            tries++;

        } while (LoginFaild);

        clsProcessesMenue::Main_Menu_Screen();
        return true;
    }
public:
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }
};

