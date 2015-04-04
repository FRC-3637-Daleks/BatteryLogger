#include <string>
#include <cstdlib>
#include <functional>

#include "DiagRoboRIO/LogService.h"

using namespace std;
using namespace DRR;

double GetVoltage(int batID)
{
	return (rand() % 11) * 1.5;
}

int main(int argc, char **argv)
{
	LogService::Preferences().log_home_path = "/home/edward/battery-log/";
	LogService::Preferences().dashboard_root = "battery_logger";
	
	for(int i = 0; i < 6; i++)
	{
		LogService::AddBindedLog<double>("battery_cart", LogService::AddID("battery", i), std::bind(GetVoltage, i), -1);
	}
	
	LogService::Start();
	
	while(true)
		this_thread::sleep_for(chrono::seconds(1));
	
	return 0;	
}