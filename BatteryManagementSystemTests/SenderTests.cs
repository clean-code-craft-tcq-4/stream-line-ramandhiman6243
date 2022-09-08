using BatteryManagementSystem;
using Xunit;

namespace BatteryManagementSystemTests
{
    public class SenderTests
    {
        public float[] mockFloatValues = new float[] { 10.3f, 20.54f, 100.54f, 30.32f };
        public int[] mockIntValues = new int[] { 10, 20, 30, 40 };

        Sensor<float> GetTemperatureSensor(float[] mockFloatValues)
        {
            MockStream<float> floatStream = new MockStream<float>(mockFloatValues);
            var temperatureSensor = new Sensor<float>(floatStream);
            return temperatureSensor;
        }

        Sensor<int> GetChargeRateSensor(int[] mockIntValues)
        {
            MockStream<int> intStream = new MockStream<int>(mockIntValues);
            var chargeRateSensor = new Sensor<int>(intStream);
            return chargeRateSensor;
        }

        Sender GetSenderWithMockSensors()
        {
            var serializer = new JsonSerializer();
            Sender sender = new Sender(GetTemperatureSensor(mockFloatValues), GetChargeRateSensor(mockIntValues), new JsonSerializer());
            return sender;
        }

        Readings GetMockReadings(int count)
        {
            Readings readings = new Readings();
            for (int i = 0; i < count; i++)
            {
                AddMockReading(readings, i);
            }
            return readings;
        }

        private void AddMockReading(Readings readings, int i)
        {
            if (i < mockFloatValues.Length)
                readings.AddReading(mockFloatValues[i], mockIntValues[i]);
            else
                readings.AddReading(0, 0);
        }

        [Fact]
        private void TestStringConversionOutput()
        {
            string actualReadings = GetSenderWithMockSensors().GenerateReadingsToString(4);
            string expectedReadings = new JsonSerializer().Serialize(GetMockReadings(4));

            Assert.Equal(expectedReadings, actualReadings);
        }

        [Fact]
        private void TestPrintOutput()
        {
            string actualReadings = string.Empty;
            GetSenderWithMockSensors().PrintReadingsToConsole(4, Print);

            void Print(string value)
            {
                actualReadings = value;
            }

            string expectedReadings = new JsonSerializer().Serialize(GetMockReadings(4));

            Assert.Equal(expectedReadings, actualReadings);
        }

        [Fact]
        private void TestMockStreamOverflow()
        {
            string actualReadings = GetSenderWithMockSensors().GenerateReadingsToString(7);
            string expectedReadings = new JsonSerializer().Serialize(GetMockReadings(7));

            Assert.Equal(expectedReadings, actualReadings);
        }
    }
}
