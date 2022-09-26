#include <iostream>
#include "json/json.h"
#include <fstream>
#include "Sender_Parser.hpp"
#include <bits/stdc++.h>

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

void Get_Maximum(struct Reading temp_chargerate, int number_of_readings, Maximum &MaxOfAttribute) {

	MaxOfAttribute.MAX_TEMP = MAX_Reading(temp_chargerate.Temperature, number_of_readings);
	MaxOfAttribute.MAX_CHARGE_RATE = MAX_Reading(temp_chargerate.Charge_Rate, number_of_readings);

}

void Get_Minimum(struct Reading temp_chargerate, int number_of_readings, Minimum &MinOfAttribute) {

	MinOfAttribute.MIN_TEMP = MIN_Reading(temp_chargerate.Temperature, number_of_readings);
	MinOfAttribute.MIN_CHARGE_RATE = MIN_Reading(temp_chargerate.Charge_Rate, number_of_readings);

}

int main(){

	Reading Total_Readings;
	Maximum MaxOfAttribute;
	Minimum MinOfAttribute;
	jsonparser(Total_Readings);
	Get_Maximum(Total_Readings, G_TOTAL_READINGS, MaxOfAttribute);
	Get_Minimum(Total_Readings, G_TOTAL_READINGS, MinOfAttribute);

	cout << "max.charge" << MaxOfAttribute.MAX_CHARGE_RATE;
	cout << "max.TEMP" << MaxOfAttribute.MAX_TEMP;

}


