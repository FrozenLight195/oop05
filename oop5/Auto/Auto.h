#pragma once
class Auto
{
private:
	int maxspeed;
	int pocetkol;
	int barva;
public:
	Auto(int speed, int wheel, int color)
	{
		this->barva = color;
		this->maxspeed = speed;
		this->pocetkol = wheel;
	};
	~Auto() {};

	int getSpeed();
	int getColor();
	int getWheels();
};

class OsobniAutomobil : public Auto
{
private:
	bool tahac;
public:
	OsobniAutomobil(int speed, int wheel, int color, bool tahac) : Auto(speed, wheel, color)
	{
		this->tahac = tahac;
	}

	bool isTugger();
};

class Nakladak : public Auto
{
private:
	int vahaNakladu;
public:
	Nakladak(int speed, int wheel, int color, int load) : Auto(speed, wheel, color)
	{
		this->vahaNakladu = load;
	}

	void loadmore(int load)	{
		this->vahaNakladu += load;
	}

	int unload(int unload)
	{
		this->vahaNakladu -= unload;
		return unload;
	}
};