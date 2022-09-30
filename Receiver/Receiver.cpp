#include <iostream>
#include "json/json.h"
#include <fstream>
#include "Receiver.hpp"

using namespace std;
using namespace Json;


void jsonparser(struct Reading &Sampled_Reading) {

	std::ifstream file_input("senderOutputExample.json");
	Json::Reader reader;
	Json::Value root;
	reader.parse(file_input, root);

	Value readings = root["readings"];

	for (int i = 0; i < readings.size(); i++) {
		Sampled_Reading.Temperature[i] = readings[i]["temperature"].asFloat();
		Sampled_Reading.Charge_Rate[i] = readings[i]["chargeRate"].asInt();
	}

}

void Sorting(struct Reading &temp_chargerate)
{
	sort(temp_chargerate.Temperature, temp_chargerate.Temperature + G_TOTAL_READINGS, greater<int>());
	sort(temp_chargerate.Charge_Rate, temp_chargerate.Charge_Rate + G_TOTAL_READINGS, greater<int>());
}

void Get_Maximum(struct Reading temp_chargerate, Maximum &MaxOfAttribute){

	Sorting(temp_chargerate);

	for (int i = 0; i < G_TOTAL_READINGS; i++) {
		cout << temp_chargerate.Temperature[i] << endl;
	}

	MaxOfAttribute.MAX_TEMP = temp_chargerate.Temperature[0];
	MaxOfAttribute.MAX_CHARGE_RATE = temp_chargerate.Charge_Rate[0];
}


void Get_Minimum(struct Reading temp_chargerate, Minimum &MinOfAttribute) {

	Sorting(temp_chargerate);

	MinOfAttribute.MIN_TEMP = temp_chargerate.Temperature[G_TOTAL_READINGS - 1];
	MinOfAttribute.MIN_CHARGE_RATE = temp_chargerate.Charge_Rate[G_TOTAL_READINGS - 1];

}

// int main(){

// 	Reading Sampled_Reading;
// 	Maximum MaxOfAttribute;
// 	Minimum MinOfAttribute;
// 	SimpleMovingAverage SMA_Temperature(G_LastnReadings);
// 	SimpleMovingAverage SMA_ChargeRate(G_LastnReadings);

// 	jsonparser(Sampled_Reading);
// 	Get_Maximum(Sampled_Reading, MaxOfAttribute);
// 	Get_Minimum(Sampled_Reading, MinOfAttribute);

// 	cout << "Maximum charge rate = " << MaxOfAttribute.MAX_CHARGE_RATE << endl;
// 	cout << "Maximum Temperature = " << MaxOfAttribute.MAX_TEMP << endl;
// 	cout << endl;

// 	cout << "Minimum charge rate = " << MinOfAttribute.MIN_CHARGE_RATE << endl;
// 	cout << "Minimum Temperature = " << MinOfAttribute.MIN_TEMP << endl;
// 	cout << endl;

// 	for (double x : Sampled_Reading.Temperature) {
// 		SMA_Temperature.addData(x);
// 		cout << "New number added is " << x << ", Simple Moving Average of temperature reading = " << SMA_Temperature.getMean() << endl; }

// 	cout << endl;

// 	for (double x : Sampled_Reading.Charge_Rate) {
// 		SMA_ChargeRate.addData(x);
// 		cout << "New number added is " << x << ", Simple Moving Average of charge rate reading = " << SMA_ChargeRate.getMean() << endl; }

// }
