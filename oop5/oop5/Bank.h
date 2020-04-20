#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Client.h"
#include "Account.h"
using namespace std;
class Bank
{
private:
    static double standartInterestRate;

    Client** clients;
    int clientsCount;

    Account** accounts;
    int accountsCount;

public:
    Bank(int c, int a);
    ~Bank();

    void SetStandartInterest(double ir);
    Client* GetClient(int c);
    Account* GetAccount(int n);

    Client* CreateClient(int c, string n);
    Account* CreateAccount(int num, Client* c);
    Account* CreateAccount(int num, Client* c, double ir);
    Account* CreateAccount(int num, Client* c, Client* p);
    Account* CreateAccount(int num, Client* c, Client* p, double ir);
    void AddInterest();
};

