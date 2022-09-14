#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <streambuf>
#include <ostream>
#include <string>
#include <fstream>
#include "json/json.h"

using namespace std;

int main() {
    std::ifstream file_input("senderOutputExample.json");
    Json::Reader reader;
    Json::Value root;
    reader.parse(file_input, root);
    std::cout << root;
    return 0;
}