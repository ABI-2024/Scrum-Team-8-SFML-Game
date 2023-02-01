#pragma once
class CSVcontrol
{

private:
	static short config[5];

	static short rowStart[5];
public:
	static void loadConfig();
	static int getEventAmount(int number);
	static int getEventStart(int number);
};

