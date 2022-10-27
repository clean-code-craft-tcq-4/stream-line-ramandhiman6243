namespace BatteryManagementSystem
{
    public class Sensor<T> : ISensor<T>
    {
        protected IStream<T> stream;

        public Sensor(IStream<T> stream)
        {
            this.stream = stream;
        }

        public T Read()
        {
            return stream.ReadNext();
        }
    }
}
