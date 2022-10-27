namespace BatteryManagementSystem
{
    public interface ISensor<T>
    {
        T Read();
    }
}
