#ifndef SENDER_PARSER_HPP
#define SENDER_PARSER_HPP

#include <iostream>
#include "bits/bits-stdc++.h"

const int G_TOTAL_READINGS = 5;

struct Reading
{
	float Temperature[G_TOTAL_READINGS] = {0};
	int Charge_Rate[G_TOTAL_READINGS] = {0};
};

struct Maximum
{
	float MAX_TEMP;
	int MAX_CHARGE_RATE;
};

struct Minimum
{
	float MIN_TEMP;
	int MIN_CHARGE_RATE;
};

void jsonparser(struct Reading &Total_Readings);

void Sorting(struct Reading &temp_chargerate);

void Get_Maximum(struct Reading temp_chargerate, Maximum &MaxOfAttribute);

void Get_Minimum(struct Reading temp_chargerate, Minimum &MinOfAttribute);

#endif