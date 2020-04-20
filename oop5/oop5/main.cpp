#include <iostream>
#include <string>
#include <list>
#include "Bank.h"

using namespace std;
int main()
{
	Bank *banka = new Bank(250, 250);
	
	for (size_t i = 0; i < 30; i++)
	{
		string jumbo = "Jumbo"; char buffer[8]; 
		sprintf_s(buffer, "%d", i); auto name=jumbo.append(buffer);
		//printf("%s\n", jumbo.c_str());

		banka->CreateClient(i, name);
	}
	for (size_t i = 0; i < 30; i++) {
		banka->CreateAccount(i, banka->GetClient(i));
		i++;
		banka->CreateAccount(i, banka->GetClient(i), banka->GetClient(i));
	}
	for (size_t i = 0; i < 30; i++ )
	{
		//account owners and partners
		printf("%s\n\n", banka->GetAccount(i)->GetOwner()->GetName().c_str());
		i++;
		printf("%s\n%s\n\n", banka->GetAccount(i)->GetOwner()->GetName().c_str(), ((PartnerAccount*)(banka->GetAccount(i)))->GetPartner()->GetName().c_str());
	}

	int id_karla = 30;
	banka->CreateClient(id_karla, "Karel");
	banka->CreateAccount(id_karla, banka->GetClient(id_karla));
	banka->GetAccount(id_karla)->Deposit(1000);
	banka->AddInterest();
	printf("Karel vložil 1000 a s urokem 0.5%%  ma ted %.3f", banka->GetAccount(id_karla)->GetBalance());

	return 5;
}
