using BatteryManagementSystem;
using Xunit;

namespace BatteryManagementSystemTests
{
    public class SenderTests
    {
        [Fact]
        private void TestReadingsConversion()
        {
            MockStream<float> floatStream = new MockStream<float>(new float[] { 10.3f, 20.54f, 100.54f, 30.32f });
            var temperatureSensor = new Sensor<float>(floatStream);

            MockStream<int> intStream = new MockStream<int>(new int[] { 10, 20, 30, 40 });
            var chargeRateSensor = new Sensor<int>(intStream);

            var serializer = new JsonSerializer();

            Sender sender = new Sender(temperatureSensor, chargeRateSensor, serializer);

            Readings actualReadings = sender.GenerateReadings(4);

            Readings expectedReadings = new Readings();
            expectedReadings.AddReading(10.3f, 10);
            expectedReadings.AddReading(20.54f, 20);
            expectedReadings.AddReading(100.54f, 30);
            expectedReadings.AddReading(30.32f, 40);

            Assert.Equivalent(expectedReadings, actualReadings, true);
        }

        [Fact]
        private void TestStringConversionOutput()
        {
            MockStream<float> floatStream = new MockStream<float>(new float[] { 10.3f, 20.54f, 100.54f, 30.32f });
            var temperatureSensor = new Sensor<float>(floatStream);

            MockStream<int> intStream = new MockStream<int>(new int[] { 10, 20, 30, 40 });
            var chargeRateSensor = new Sensor<int>(intStream);

            var serializer = new JsonSerializer();

            Sender sender = new Sender(temperatureSensor, chargeRateSensor, serializer);

            string actualReadings = sender.GenerateReadingsToString(4);

            Readings manualReadings = new Readings();
            manualReadings.AddReading(10.3f, 10);
            manualReadings.AddReading(20.54f, 20);
            manualReadings.AddReading(100.54f, 30);
            manualReadings.AddReading(30.32f, 40);

            string expectedReadings = new JsonSerializer().Serialize(manualReadings);

            Assert.Equal(expectedReadings, actualReadings);
        }

        [Fact]
        private void TestPrintOutput()
        {
            MockStream<float> floatStream = new MockStream<float>(new float[] { 10.3f, 20.54f, 100.54f, 30.32f });
            var temperatureSensor = new Sensor<float>(floatStream);

            MockStream<int> intStream = new MockStream<int>(new int[] { 10, 20, 30, 40 });
            var chargeRateSensor = new Sensor<int>(intStream);

            var serializer = new JsonSerializer();

            Sender sender = new Sender(temperatureSensor, chargeRateSensor, serializer);

            string actualReadings = string.Empty;
            sender.PrintReadingsToConsole(4, Print);

            void Print(string value)
            {
                actualReadings = value;
            }

            Readings manualReadings = new Readings();
            manualReadings.AddReading(10.3f, 10);
            manualReadings.AddReading(20.54f, 20);
            manualReadings.AddReading(100.54f, 30);
            manualReadings.AddReading(30.32f, 40);

            string expectedReadings = new JsonSerializer().Serialize(manualReadings);

            Assert.Equal(expectedReadings, actualReadings);
        }
    }
}
