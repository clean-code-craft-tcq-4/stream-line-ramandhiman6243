using System.Collections.Generic;

namespace BatteryManagementSystem
{
    public class Readings
    {
        public List<Reading> readings;

        public Readings()
        {
            readings = new List<Reading>();
        }

        public void AddReading(float temperature, int chargeRate)
        {
            Reading reading = new Reading(temperature, chargeRate);
            readings.Add(reading);
        }
    }

    public class Reading
    {
        public float temperature;
        public int chargeRate;

        public Reading(float temperature, int chargeRate)
        {
            this.temperature = temperature;
            this.chargeRate = chargeRate;
        }
    }
}
