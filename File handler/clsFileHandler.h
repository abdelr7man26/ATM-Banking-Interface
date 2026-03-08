#pragma once
#include "clsClient.h"

class clsFileHandler 
{
public:
    static vector <clsClient> _fillFromFile(string fileName) {

        vector <clsClient> clients;

        fstream file;
        file.open(fileName, ios::in);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.empty())
                {
                    continue;
                }
                clsClient client = clsClient::_convertLineIntoObject(line);
                clients.push_back(client);
            }
            file.close();
        }
        return clients;
    }

    static void _saveToFile(string fileName, vector <clsClient> vClients) {
        fstream file;
        file.open(fileName, ios::out);

        string attributesline;

        if (file.is_open()) {
            for (clsClient client : vClients)
            {

                attributesline = clsClient::_convertObjectIntoLine(client);
                file << attributesline << endl;

            }
            file.close();
        }
    }

    static void _saveOneClientToFile(string fileName, clsClient client) {
        fstream file;
        file.open(fileName, ios::out | ios::app);

        string attributesline;

        if (file.is_open()) {

            attributesline = clsClient::_convertObjectIntoLine(client);
            file << attributesline << endl;

            file.close();
        }
    }


    static void _saveTransferHistoryToFile(clsClient Sender, int amount, clsClient Reciver) {
        fstream file;
        file.open("F:/projects in OOP programming/banksystem/Database/Transfer Log.txt", ios::out);

        string attributesline;

        if (file.is_open()) {


            attributesline = clsClient::_convertTranferHistoryToLine(Sender, amount, Reciver);
            file << attributesline << endl;


            file.close();
        }
    }

    static  vector <vector<string>> _LoadLogHistoryFromFile() {
        vector <vector<string>> vattributes;

        fstream file;
        file.open("F:/projects in OOP programming/banksystem/Database/Transfer Log.txt", ios::in);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.empty())
                {
                    continue;
                }

                vattributes.push_back(clsClient::_convertTransferLineIntoVector(line));
            }
            file.close();
        }
        return vattributes;

    }
};

