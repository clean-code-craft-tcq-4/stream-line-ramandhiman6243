using BatteryManagementSystem;
using Xunit;

namespace BatteryManagementSystemTests
{
    public class SenderTests
    {
        //TODO: Implement test cases
        [Fact]
        private void TestSensorLimits()
        {
            IntReadingGenerator readingGenerator = new IntReadingGenerator(20, 80);
            var chargeRateSensor = new Sensor<int>(readingGenerator);

            for (int i = 0; i < 10; i++)
            {
                int generatedValue = chargeRateSensor.Read();
                Assert.True(generatedValue > 20);
                Assert.True(generatedValue <= 80);
            }
        }
    }
}
