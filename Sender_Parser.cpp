#include <iostream>
#include "json/json.h"
#include <fstream>
#include "Sender_Parser.hpp"

using namespace std;
using namespace Json;


int main()
{
	Reading Total_Readings[G_TOTAL_READINGS];
	std::ifstream file_input("senderOutputExample.json");
	Json::Reader reader;
	Json::Value root;
	reader.parse(file_input, root);

	Value readings = root["readings"];

	for (int i = 0; i < readings.size(); i++) {
		//cout << "Temperature: " << readings[i]["temperature"] << endl;
		//cout << "Charge Rate: " << readings[i]["chargeRate"] << endl << endl;
		Total_Readings[i].Temperature = readings[i]["temperature"].asFloat();
		Total_Readings[i].Charge_Rate = readings[i]["chargeRate"].asInt();
		cout << "Temperature: " << Total_Readings[i].Temperature << endl;
		cout << "Charge Rate: " << Total_Readings[i].Charge_Rate << endl << endl;
	}

	return 0;
}