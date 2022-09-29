#include <iostream>
#include "json/json.h"
#include <fstream>
#include "Sender_Parser.hpp"

using namespace std;
using namespace Json;


void jsonparser(struct Reading &Total_Readings) {

	std::ifstream file_input("senderOutputExample.json");
	Json::Reader reader;
	Json::Value root;
	reader.parse(file_input, root);

	Value readings = root["readings"];

	for (int i = 0; i < readings.size(); i++) {
		Total_Readings.Temperature[i] = readings[i]["temperature"].asFloat();
		Total_Readings.Charge_Rate[i] = readings[i]["chargeRate"].asInt();
		cout << "Temperature: " << Total_Readings.Temperature[i] << endl;
		cout << "Charge_Rate: " << Total_Readings.Charge_Rate[i] << endl;
	}

}

void Sorting(struct Reading &temp_chargerate)
{
	sort(temp_chargerate.Temperature, temp_chargerate.Temperature + G_TOTAL_READINGS, greater<int>());
	sort(temp_chargerate.Charge_Rate, temp_chargerate.Charge_Rate + G_TOTAL_READINGS, greater<int>());
}

void Get_Maximum(struct Reading temp_chargerate, Maximum &MaxOfAttribute){

	Sorting(temp_chargerate);

	MaxOfAttribute.MAX_TEMP = temp_chargerate.Temperature[0];
	MaxOfAttribute.MAX_CHARGE_RATE = temp_chargerate.Charge_Rate[0];
}


void Get_Minimum(struct Reading temp_chargerate, Minimum &MinOfAttribute) {

	Sorting(temp_chargerate);

	MinOfAttribute.MIN_TEMP = temp_chargerate.Temperature[G_TOTAL_READINGS - 1];
	MinOfAttribute.MIN_CHARGE_RATE = temp_chargerate.Charge_Rate[G_TOTAL_READINGS - 1];

}

int main(){

	Reading Total_Readings;
	Maximum MaxOfAttribute;
	Minimum MinOfAttribute;
	jsonparser(Total_Readings);
	Get_Maximum(Total_Readings, MaxOfAttribute);
	Get_Minimum(Total_Readings, MinOfAttribute);

	cout << "max.charge = " << MaxOfAttribute.MAX_CHARGE_RATE << endl;
	cout << "max.TEMP = " << MaxOfAttribute.MAX_TEMP << endl;

	cout << "min.charge = " << MinOfAttribute.MIN_CHARGE_RATE << endl;
	cout << "min.TEMP = " << MinOfAttribute.MIN_TEMP << endl;

}


