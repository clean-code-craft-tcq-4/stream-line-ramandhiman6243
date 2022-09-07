namespace BatteryManagementSystem
{
    public class Stream<T> : IStream<T>
    {
        T[] values;

        int currentIndex = 0;

        public Stream (T[] values)
        {
            this.values = values;
        }

        public T ReadNext()
        {
            if (currentIndex >= values.Length)
                currentIndex = 0;

            T currentReading = values[currentIndex];
            currentIndex++;
            return currentReading;
        }
    }
}
