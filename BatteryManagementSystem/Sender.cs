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

        public string GenerateOutput(int numberOfValues)
        {
            Readings readings = new Readings();

            for (int i = 0; i < numberOfValues; i++)
            {
                AddNewReading(readings, ReadTemperatureSensor(), ReadChargeRateSensor());
            }

            return Serialize(readings);
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

        public string Serialize(Readings readings)
        {
            string serializedValue = serializer.Serialize(readings);
            return serializedValue;
        }
    }
}
