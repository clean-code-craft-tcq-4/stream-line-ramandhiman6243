using Newtonsoft.Json;

namespace BatteryManagementSystem
{
    public class JsonSerializer : ISerializer
    {
        public string Serialize(object objectToSerialize)
        {
            return JsonConvert.SerializeObject(objectToSerialize, Formatting.Indented);
        }
    }
}
