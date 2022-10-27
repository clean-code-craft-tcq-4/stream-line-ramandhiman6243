using System;
using System.Collections.Generic;

namespace BatteryManagementSystem
{
    public class Sender
    {
        private ISensor<float> temperatureSensor;
        private ISensor<int> chargeRateSensor;

        private ISerializer serializer;

        public Sender(ISensor<float> temperatureSensor, ISensor<int> chargeRateSensor, ISerializer serializer)
        {
            this.temperatureSensor = temperatureSensor;
            this.chargeRateSensor = chargeRateSensor;
            this.serializer = serializer;
        }

        public Readings GenerateReadings(int numberOfValues)
        {
            Readings readings = new Readings();

            for (int i = 0; i < numberOfValues; i++)
            {
                AddNewReading(readings, ReadTemperatureSensor(), ReadChargeRateSensor());
            }

            return readings;
        }

        public string ReadingsToString(Readings readings)
        {
            string serializedReadings = Serialize(readings);
            return serializedReadings;
        }

        public string GenerateReadingsToString(int numbeOfValues)
        {
            var readings = GenerateReadings(numbeOfValues);
            string output = ReadingsToString(readings);
            return output;
        }

        public void PrintReadingsToConsole(int numberOfValues, Action<string> printFunction)
        {
            string stringOutput = GenerateReadingsToString(numberOfValues);
            printFunction?.Invoke(stringOutput);
        }

        private float ReadTemperatureSensor()
        {
            return temperatureSensor.Read();
        }

        private int ReadChargeRateSensor()
        {
            return chargeRateSensor.Read();
        }

        private void AddNewReading(Readings readings, float temperatureReading, int chargeRateReading)
        {
            readings.AddReading(temperatureReading, chargeRateReading);
        }

        private string Serialize(Readings readings)
        {
            string serializedValue = serializer.Serialize(readings);
            return serializedValue;
        }
    }
}
