#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <streambuf>
#include <ostream>
#include <string>
using namespace std;

void print(const string str, ostream & output)
{
    output << str;
}

int main ()
{
    std::string Sender_output = R"(temperature: 86.17, chargeRate: 71
temperature: 5.85 , chargeRate: 74
temperature: 30.12, chargeRate: 61)";
    print(Sender_output, cout);
    ofstream filestream("filename.out");
    print(Sender_output, filestream);

    return 0;
}