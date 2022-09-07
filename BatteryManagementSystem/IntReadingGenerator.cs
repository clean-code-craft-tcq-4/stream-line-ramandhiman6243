using System;

namespace BatteryManagementSystem
{
    public class IntReadingGenerator : ReadingGenerator<int>
    {
        public IntReadingGenerator(int minValue, int maxValue) : base(minValue, maxValue) { }

        public override int ReadNext()
        {
            int reading = Random.Next(minValue, maxValue);
            return reading;
        }
    }
}
