using BatteryManagementSystem;
using Xunit;

namespace BatteryManagementSystemTests
{
    public class SensorTests
    {
        [Fact]
        private void TestIntSensorLimits()
        {
            IntReadingGenerator readingGenerator = new IntReadingGenerator(20, 80);
            var chargeRateSensor = new Sensor<int>(readingGenerator);

            for (int i = 0; i < 10; i++)
            {
                int generatedValue = chargeRateSensor.Read();
                Assert.True(generatedValue >= 20);
                Assert.True(generatedValue <= 80);
            }
        }

        [Fact]
        private void TestFloatSensorLimits()
        {
            FloatReadingGenerator readingGenerator = new FloatReadingGenerator(0, 100, 2);
            var temperatureSensor = new Sensor<float>(readingGenerator);

            for (int i = 0; i < 10; i++)
            {
                float generatedValue = temperatureSensor.Read();
                Assert.True(generatedValue > 0);
                Assert.True(generatedValue <= 100);
            }
        }

        [Fact]
        private void TestFixedValuesSensor()
        {
            var values = new int[] { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
            MockStream<int> stream = new MockStream<int>(values);
            var chargeRateSensor = new Sensor<int>(stream);

            for (int i = 0; i < values.Length; i++)
            {
                int generatedValue = chargeRateSensor.Read();
                Assert.Equal(values[i], generatedValue);
            }
        }
    }
}
