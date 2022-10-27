using System;

namespace BatteryManagementSystem
{
    public class Utility
    {
        public static float RoundToDecimalPoints(float number, int noOfDecimalPoints)
        {
            number = (float)Math.Round(number, noOfDecimalPoints);
            return number;
        }

        public static float ScaleNumberIntoRange(float number, float minValue, float maxValue)
        {
            float range = maxValue - minValue;
            float scaled = (number * range) + minValue;
            return scaled;
        }
    }
}
