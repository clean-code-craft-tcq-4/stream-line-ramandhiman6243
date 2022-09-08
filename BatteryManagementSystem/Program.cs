using System;

namespace BatteryManagementSystem
{
    class Program
    {
        static void Main(string[] args)
        {
            FloatReadingGenerator temperatureStream = new FloatReadingGenerator(0, 100, 2);
            IntReadingGenerator chargeRateStream = new IntReadingGenerator(20, 80);

            var temperatureSensor = new Sensor<float>(temperatureStream);
            var chargeRateSensor = new Sensor<int>(chargeRateStream);

            Sender sender = new Sender(temperatureSensor, chargeRateSensor,  new JsonSerializer());
            sender.PrintReadingsToConsole(50, Console.WriteLine);
        }
    }
}
