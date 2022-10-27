#ifndef RECEIVER_HPP
#define RECEIVER_HPP

#include <iostream>
#include "bits/bits-stdc++.h"

using namespace std;

const int G_TOTAL_READINGS = 10;
const int G_LastnReadings = 5;

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

class SimpleMovingAverage {

  // queue used to store list so that we get the average
  queue<double> Dataset;
  int LastnReading;
  double sum;

  public:

  SimpleMovingAverage(int nReading) { LastnReading = nReading; }

  // function to add new data in the list and update the sum so that we get the new mean
  void addData(double num)
  {
    sum += num;
    Dataset.push(num);

    // Updating size so that length of data set should be equal to LastnReading as a normal mean has
    if (Dataset.size() > LastnReading) {
      sum -= Dataset.front();
      Dataset.pop();
    }
  }

  // function to calculate mean
  double getMean() { return sum / LastnReading; }
};


void jsonparser(struct Reading &Total_Readings);

void Sorting(struct Reading &temp_chargerate);

void Get_Maximum(struct Reading temp_chargerate, Maximum &MaxOfAttribute);

void Get_Minimum(struct Reading temp_chargerate, Minimum &MinOfAttribute);

#endif