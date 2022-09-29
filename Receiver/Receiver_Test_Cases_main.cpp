#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <iostream>
#include "Receiver.hpp"
using namespace std;

// As a first step, only considering to detect continuous ranges in the samples
TEST_CASE("POSITIVE TEST CASE 1 - Maximum Charge Rate/Temperature ") {

    //REQUIRE(SampleRangeReadings(Current_Samples, Current_Samples_size, 2) == true);

	Maximum MaxOfAttribute;
    Reading Sampled_Reading;

    Sampled_Reading.Charge_Rate[] = { 4, 5, 8, 9, 12, 15, 91, 19, 99, 0 };
    Sampled_Reading.Temperature[] = { 4.4, 3.5, 8.8, 1.9, 1.2, 1.5, 9.1, 1.4, 9.9, 0.0 };

	Get_Maximum(Sampled_Reading, MaxOfAttribute);

	cout << "Maximum charge rate = " << MaxOfAttribute.MAX_CHARGE_RATE << endl;
	cout << "Maximum Temperature = " << MaxOfAttribute.MAX_TEMP << endl;
	cout << endl;

    REQUIRE(MaxOfAttribute.MAX_CHARGE_RATE == 99);
    REQUIRE(MaxOfAttribute.MAX_TEMP == 9.9);
}
