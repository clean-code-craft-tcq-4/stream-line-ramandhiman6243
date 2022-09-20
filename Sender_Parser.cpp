#include <iostream>
#include "json/json.h"
#include <fstream>

using namespace std;
using namespace Json;

int main()
{
	std::ifstream file_input("senderOutputExample.json");
	Json::Reader reader;
	Json::Value root;
	reader.parse(file_input, root);

	Value readings = root["readings"];

	for (int i = 0; i < readings.size(); i++) {
		cout << "Temperature: " << readings[i]["temperature"] << endl;
		cout << "Charge Rate: " << readings[i]["chargeRate"] << endl << endl;
	}

	return 0;
}