#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;
class Client
{
private:
    static int objectCount;
    int code;
    string name;
public:
    static int GetobjectCount();
    Client(int c, string n);
    ~Client();
    int GetCode();
    string GetName();
};

