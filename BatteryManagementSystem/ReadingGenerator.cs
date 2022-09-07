using System;

namespace BatteryManagementSystem
{
    public abstract class ReadingGenerator<T> : IStream<T>
    {
        protected T minValue;
        protected T maxValue;

        protected Random Random
        {
            get => new Random();
        }

        public ReadingGenerator(T minValue, T maxValue)
        {
            this.minValue = minValue;
            this.maxValue = maxValue;
        }

        public abstract T ReadNext();
    }
}
