#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <iostream>
#include "Receiver.hpp"
using namespace std;

int Sampled_Charge_Rate[] = { 4, 5, 8, 9, 12, 15, 91, 19, 99, 0 };
float Sampled_Temperature[] = { 4.4, 3.5, 8.8, 1.9, 1.2, 1.5, 9.1, 1.4, 9.9, 0.1 };

// Maximum Charge Rate - Temperature
TEST_CASE("Maximum Charge Rate/Temperature ") {

	Maximum MaxOfAttribute;
    Reading Sampled_Reading;

    for (int i = 0; i < 10; i++) {
        Sampled_Reading.Charge_Rate[i] = Sampled_Charge_Rate[i];
        Sampled_Reading.Temperature[i] = Sampled_Temperature[i];
    }

	Get_Maximum(Sampled_Reading, MaxOfAttribute);

	cout << "Maximum charge rate = " << MaxOfAttribute.MAX_CHARGE_RATE << endl;
	cout << "Maximum Temperature = " << MaxOfAttribute.MAX_TEMP << endl;
	cout << endl;

    REQUIRE(MaxOfAttribute.MAX_CHARGE_RATE == 99);
    REQUIRE(MaxOfAttribute.MAX_TEMP == 9.9f);
}

// Minimum Charge Rate - Temperature
TEST_CASE("Minimum Charge Rate/Temperature ") {

	Minimum MinOfAttribute;
    Reading Sampled_Reading;

    for (int i = 0; i < 10; i++) {
        Sampled_Reading.Charge_Rate[i] = Sampled_Charge_Rate[i];
        Sampled_Reading.Temperature[i] = Sampled_Temperature[i];
    }

	Get_Minimum(Sampled_Reading, MinOfAttribute);

	cout << "Minimum charge rate = " << MinOfAttribute.MIN_CHARGE_RATE << endl;
	cout << "Minimum Temperature = " << MinOfAttribute.MIN_TEMP << endl;
	cout << endl;

    REQUIRE(MinOfAttribute.MIN_CHARGE_RATE == 0);
    REQUIRE(MinOfAttribute.MIN_TEMP == 0.1f);
}

// Simple Moving Average
TEST_CASE("Simple Moving Average of latest 5 values Charge Rate/Temperature ") {

    SimpleMovingAverage SMA_Temperature(G_LastnReadings);
 	SimpleMovingAverage SMA_ChargeRate(G_LastnReadings);

    for (int i = 0; i < 5; i++) {
        SMA_Temperature.addData(Sampled_Temperature[i]);
        SMA_ChargeRate.addData(Sampled_Charge_Rate[i]);
    }

    float temp_average, charge_rate_average;

 	cout << "Simple Moving Average of temperature reading = " << SMA_Temperature.getMean() << endl;
    temp_average = SMA_Temperature.getMean();
    REQUIRE(temp_average == 3.96f);

 	cout << endl;

	cout << "Simple Moving Average of charge rate reading = " << SMA_ChargeRate.getMean() << endl;
    charge_rate_average = SMA_Temperature.getMean();
    REQUIRE(charge_rate_average == 7.6f);
}