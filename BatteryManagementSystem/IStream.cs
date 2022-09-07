namespace BatteryManagementSystem
{
    public interface IStream<T>
    {
        T ReadNext();
    }
}
