#pragma once
class CSVcontrol
{

private:
	static short config[4];
public:
	static void loadConfig();
	static int getConfig(int confignumber);

};

