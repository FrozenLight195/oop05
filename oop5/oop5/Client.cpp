#include "Client.h"

using namespace std;

int Client::objectCount = 0;

Client::Client(int code, string name)
{
    this->code = code;
    this->name = name;
    Client::objectCount++;
}

Client::~Client()
{
    Client::objectCount--;
}

int Client::GetobjectCount()
{
    return Client::objectCount;
}

int Client::GetCode()
{
    return this->code;
};

string Client::GetName()
{
    return this->name;
};
