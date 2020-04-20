#include "Bank.h"

Bank::Bank(int c, int a)
{
	Client** cli = (Client**)malloc(c * sizeof(Client*));

	this->clients = cli;
	this->clientsCount = c;

	Account** acc = (Account**)malloc(c * sizeof(Account*));

	this->accounts = acc;
	this->accountsCount = a;
}

Bank::~Bank()
{
	for (size_t i = 0; i < this->accountsCount; i++)
	{
		delete this->accounts[i];
	}
	for (size_t i = 0; i < this->clientsCount; i++)
	{
		delete this->clients[i];
	}
}

double Bank::standartInterestRate = 0.005;

void Bank::SetStandartInterest(double ir)
{
	this->standartInterestRate = ir;
}

Client* Bank::GetClient(int code)
{
	return this->clients[code];
}

Account* Bank::GetAccount(int num)
{
	return this->accounts[num];
}

Client* Bank::CreateClient(int code, string name)
{
	Client* res = new Client(code, name);
	this->clients[code] = res;
	return res;
}

Account* Bank::CreateAccount(int num, Client* c)
{
	Account* res = new Account(num, c);
	this->accounts[num] = res;
	return res;
}

Account* Bank::CreateAccount(int num, Client* c, double ir)
{
	Account* res = new Account(num, c, ir);
	this->accounts[num] = res;
	return res;
}

Account* Bank::CreateAccount(int num, Client* c, Client* p)
{
	Account* res = new PartnerAccount(num, c, p);
	this->accounts[num] = res;
	return res;
}

Account* Bank::CreateAccount(int num, Client* c, Client* p, double ir)
{
	Account* res = new PartnerAccount(num, c, p, ir);
	this->accounts[num] = res;
	return res;
}

void Bank::AddInterest()
{
	int count = this->accountsCount;
	for (int i = 0; i < 31; i++)
	{
		Account* pointer = accounts[i];
		if (pointer == NULL) { break; }
		this->accounts[i]->AddInterest(Bank::standartInterestRate);
	}
}
