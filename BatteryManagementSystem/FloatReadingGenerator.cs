using System;

namespace BatteryManagementSystem
{
    public class FloatReadingGenerator : ReadingGenerator<float>
    {
        int noOfDecimalPoints;

        public FloatReadingGenerator(float minValue, float maxValue, int noOfDecimalPoints) : base(minValue, maxValue)
        {
            this.noOfDecimalPoints = noOfDecimalPoints;
        }

        public override float ReadNext()
        {
            float random = CreateRandom();
            random = Utility.ScaleNumberIntoRange(random, minValue, maxValue);
            random = Utility.RoundToDecimalPoints(random, noOfDecimalPoints);
            return random;
        }

        private float CreateRandom()
        {
            float random = (float)Random.NextDouble();
            return random;
        }
    }
}
