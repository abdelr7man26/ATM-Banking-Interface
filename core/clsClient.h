#pragma once
#include "clsString.h"
#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsutility.h"

using namespace std;
class clsClient
{
protected:
    enum enMode { emptyMode = 0, updateMode = 1 };

    enMode _mode;

    string _firstName;
    string _lastName;
    string _phoneNumber;
    string _email;
    string _accountNumber;
    string _pinCode;
    float _accountBalance;

public:

    static clsClient _convertLineIntoObject(string line) {
        vector <string> attributes;
        attributes = ClsString::split(line, '#');

        return clsClient(updateMode, attributes[0], clsUtil::DecryptText(attributes[1]), attributes[2], attributes[3], attributes[4], attributes[5], stof(attributes[6]));
    }

    static string _convertObjectIntoLine(clsClient Client, char Seperator = '#')
    {
        string attributesRecord = "";
        attributesRecord += Client.AccountNumber() + Seperator;
        attributesRecord += clsUtil::EncryptText(Client.pinCode) + Seperator;
        attributesRecord += Client._firstName + Seperator;
        attributesRecord += Client._lastName + Seperator;
        attributesRecord += Client._email + Seperator;
        attributesRecord += Client._phoneNumber + Seperator;
        attributesRecord += to_string(Client.accountBalance);

        return attributesRecord;
    }

    static string _convertTranferHistoryToLine(clsClient sender, int amount, clsClient Reciver, char Seperator = '#') {
        string attributesRecord = "";
        attributesRecord += clsDate::accurateDateToString(clsDate::GetSystemDate()) + Seperator;
        attributesRecord += sender.AccountNumber() + Seperator;
        attributesRecord += to_string(sender.accountBalance) + Seperator;
        attributesRecord += to_string(amount) + Seperator;
        attributesRecord += Reciver.AccountNumber() + Seperator;
        attributesRecord += to_string(Reciver.accountBalance) + Seperator;
        attributesRecord += "ATM";
        return attributesRecord;
    }

    static vector<string> _convertTransferLineIntoVector(string line) {
        vector <string> attributes;
        attributes = ClsString::split(line, '#');

        return attributes;
    }

    void _Update();
    static clsClient find(string accountNumber);
    static clsClient find(string accountNumber, string pinCode);
    void SaveTransferLog(int amount, clsClient Reciver);
    static vector <vector<string>> LoadTransferLog();

    enum enSaveResult { saveFaild = 0, saveSucceeded = 1 };

    clsClient(enMode mode, string accountNumber, string pinCode, string firstName, string lastName, string email, string phoneNumber, float accountBalance)
        : _mode(mode), _accountNumber(accountNumber), _pinCode(pinCode), _accountBalance(accountBalance),
        _firstName(firstName), _lastName(lastName), _phoneNumber(phoneNumber), _email(email) {
    }

    bool isEmpty() {
        return (_mode == emptyMode);
    }

    void setFirstName(string firstName) {
        _firstName = firstName;
    }
    string getFirstName() {
        return _firstName;
    }
    __declspec(property(get = getFirstName, put = setFirstName)) string firstName;


    void setLastName(string lastName) {
        _lastName = lastName;
    }
    string getLastName() {
        return _lastName;
    }
    __declspec(property(get = getLastName, put = setLastName)) string lastName;

    void setPhoneNumber(string phoneNumber) {
        _phoneNumber = phoneNumber;
    }
    string getPhoneNumber() {
        return _phoneNumber;
    }
    __declspec(property(get = getPhoneNumber, put = setPhoneNumber)) string phoneNumber;


    void setEmail(string email) {
        _email = email;
    }
    string getEmail() {
        return _email;
    }
    __declspec(property(get = getEmail, put = setEmail)) string email;


    string fullName() {
        return _firstName + " " + _lastName;
    }

    string AccountNumber()
    {
        return _accountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _pinCode = PinCode;
    }
    string GetPinCode()
    {
        return _pinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string pinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _accountBalance = AccountBalance;
    }
    float GetAccountBalance()
    {
        return _accountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float accountBalance;


    static bool isCLientExist(string accountNumber) {
        clsClient client = find(accountNumber);
        return !(client.isEmpty());
    }

    enSaveResult Save()
    {

        switch (_mode)
        {
        case enMode::emptyMode:

            return enSaveResult::saveFaild;
        case enMode::updateMode:

            _Update();
            return enSaveResult::saveSucceeded;
        }

    }

    static clsClient _emptyclient(enMode mode = enMode::emptyMode, string accountNumber = "") {
        return clsClient(mode, accountNumber, "", "", "", "", "", 0);
    }

    //static clsClient createNewObject(string accountNumber) {
    //    return _emptyclient(addNew, accountNumber);
    //}

    void Deposit(double amount) {
        _accountBalance += amount;
        Save();
    }
    bool Withdraw(double amount) {
        if (amount > _accountBalance)
        {
            return false;
        }
        else
        {
            _accountBalance -= amount;
            Save();
            return true;
        }
    }

    bool Checkavailableamount(int amount) {
        if (amount <= this->accountBalance) {
            return true;
        }
        return false;
    }

    
};

// بنعمل الـ include هنا بعد ما الكلاس اتعرف بالكامل
#include "clsFileHandler.h"

inline void clsClient::_Update()
{
    vector <clsClient> _vClients = clsFileHandler::_fillFromFile("F:/projects in OOP programming/banksystem/Database/clients.txt");
    for (clsClient& C : _vClients) {
        if (C.AccountNumber() == AccountNumber()) {
            C = *this;
            break;
        }
    }
    clsFileHandler::_saveToFile("F:/projects in OOP programming/banksystem/Database/clients.txt", _vClients);
}

inline clsClient clsClient::find(string accountNumber) {
    vector <clsClient> clients = clsFileHandler::_fillFromFile("F:/projects in OOP programming/banksystem/Database/clients.txt");
    for (clsClient& client : clients) {
        if (client.AccountNumber() == accountNumber) {
            return client;
        }
    }
    return _emptyclient();
}

inline clsClient clsClient::find(string accountNumber, string pinCode) {
    vector <clsClient> clients = clsFileHandler::_fillFromFile("F:/projects in OOP programming/banksystem/Database//clients.txt");
    for (clsClient& client : clients) {
        if (client.AccountNumber() == accountNumber && client.pinCode == pinCode) {
            return client;
        }
    }
    return _emptyclient();
}

inline void clsClient::SaveTransferLog(int amount, clsClient Reciver) {
    clsFileHandler::_saveTransferHistoryToFile(*this, amount, Reciver);
}

inline vector <vector<string>> clsClient::LoadTransferLog() {
    return  clsFileHandler::_LoadLogHistoryFromFile();
}