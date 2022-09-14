#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <streambuf>
#include <ostream>
#include <string>
#include <fstream>
#include "jsoncpp/json/json.h"

using namespace std;

//#include "json/json.h"

std::ifstream file_input("senderOutputExample.json");
Json::Reader reader;
Json::Value root;
reader.parse(file_input, root);
cout << root;