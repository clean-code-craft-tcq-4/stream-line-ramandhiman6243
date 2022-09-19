#include <iostream>
#include "json/json.h"



using namespace std;
using namespace Json;



int main()
{
    char inputString[] = R"(
        {  
            "readings": [
            {
              "temperature": 86.17,
              "chargeRate": 71
            },
            {
              "temperature": 5.85,
              "chargeRate": 74
            },
            {
              "temperature": 30.12,
              "chargeRate": 61
            },
            {
              "temperature": 83.48,
              "chargeRate": 40
            },
            {
              "temperature": 45.87,
              "chargeRate": 28
            }
          ]
        }
    )";



   Value root;
    Reader reader;
    reader.parse(inputString, root);



   Value readings = root["readings"];



   for (int i = 0; i < readings.size(); i++) {
        cout << "Temperature: " << readings[i]["temperature"] << endl;
        cout << "Charge Rate: " << readings[i]["chargeRate"] << endl << endl;
    }
}