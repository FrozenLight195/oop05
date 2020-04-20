#include "Account.h"

int Account::objectCount = 0;

Account::Account(int n, Client* c)
{
	this->number = n;
	this->owner = c;
	this->balance = 0;
	this->interestRate = 0;
	Account::objectCount++;
}
Account::Account(int n, Client* c, double ir)
{
	this->number = n;
	this->owner = c;
	this->balance = 0;
	this->interestRate = ir; 
	Account::objectCount++;
}
PartnerAccount::PartnerAccount(int n, Client* c, Client* p) : Account(n,c)
{
	this->partner = p;
}
PartnerAccount::PartnerAccount(int n, Client* c, Client* p, double ir) : Account(n,c,ir)
{
	this->partner = p;
}
Account::~Account()
{
	Account::objectCount--;
}


int Account::GetNumber()
{
	return this->number;
}
double Account::GetBalance()
{
	return this->balance;
}
double Account::GetInterestRate()
{
	return this->interestRate;
}
Client* Account::GetOwner()
{
	return this->owner;
}
Client* PartnerAccount::GetPartner()
{
	return this->partner;
}
bool Account::CanWithdraw(double a)
{
	if((this->balance - a) >= 0 )
	{
		return true;
	}
	printf("Nedostatecny kredit.\nStav: %.3f\n",this->balance);
	return false;
}

void Account::Deposit(double a)
{	
	this->balance += a;
}
void Account::Withdraw(double a)
{
	if(this->CanWithdraw(a)==true)
	{ 
		this->balance -= a;
	}
}
void Account::AddInterest(double standart)
{
	if (this->interestRate != 0)
		this->balance += (this->interestRate) * (this->balance);
	else
		this->balance += (standart) * (this->balance);
}