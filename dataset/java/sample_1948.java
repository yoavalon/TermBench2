import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1948 {

    public static int calculate_cruise_altitude(Map<String, Object> aircraft, int speed, int weight) {
        int altitude = 35000;
        while (altitude > 10000) {
            altitude -= 1000;
            if ((int) aircraft.get("max_altitude") < altitude) {
                return (int) aircraft.get("max_altitude");
            }
            if (speed * weight > 1000000) {
                return altitude;
            }
        }
        return altitude;
    }

    public static void plan_trajectory(List<Map<String, Object>> aircraft_data) {
        for (Map<String, Object> aircraft : aircraft_data) {
            int altitude = calculate_cruise_altitude(aircraft, (int) aircraft.get("speed"), (int) aircraft.get("weight"));
            System.out.println("Optimal cruise altitude for " + aircraft.get("name") + ": " + altitude + " meters");
        }
    }

    public static void main(String[] args) {
        List<Map<String, Object>> aircraft_data = List.of(
            new HashMap<String, Object>() {{
                put("name", "Boeing 747");
                put("max_altitude", 43000);
                put("speed", 870);
                put("weight", 180000);
            }},
            new HashMap<String, Object>() {{
                put("name", "Airbus A380");
                put("max_altitude", 40000);
                put("speed", 900);
                put("weight", 600000);
            }},
            new HashMap<String, Object>() {{
                put("name", "Cessna 172");
                put("max_altitude", 8000);
                put("speed", 120);
                put("weight", 1000);
            }}
        );
        plan_trajectory(aircraft_data);
    }
}