namespace BatteryManagementSystem
{
    public class MockStream<T> : IStream<T>
    {
        T[] values;

        int currentIndex = 0;

        public MockStream(T[] values)
        {
            this.values = values;
        }

        public T ReadNext()
        {
            if (currentIndex < values.Length)
            {
                T currentReading = values[currentIndex];
                currentIndex++;
                return currentReading;
            }
            else
            {
                return default(T);
            }
        }
    }
}
