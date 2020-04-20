#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Client.h"
using namespace std;

class Account
{
private:
    static int objectCount;

    int number;
    double balance;
    double interestRate;

    Client* owner;

public:
    static int GetobjectCount();

    Account(int n, Client* c);
    Account(int n, Client* c, double ir);
    ~Account();

    int GetNumber();
    double GetBalance();
    double GetInterestRate();
    Client* GetOwner();
    bool CanWithdraw(double a);

    void Deposit(double a);
    void Withdraw(double a);
    void AddInterest(double standart);
};
class PartnerAccount : public Account
{
private:
    Client* partner;

public:
    PartnerAccount(int n, Client* c, Client* p);
    PartnerAccount(int n, Client* c, Client* p, double ir);
    
    Client* GetPartner();
};

