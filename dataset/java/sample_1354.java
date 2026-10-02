import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1354 {
    public static int calculateAltitudeAdjustment(int altitude, int targetAltitude, int maxChange) {
        if (altitude > targetAltitude) {
            return Math.max(-maxChange, targetAltitude - altitude);
        } else if (altitude < targetAltitude) {
            return Math.min(maxChange, targetAltitude - altitude);
        }
        return 0;
    }

    public static List<Map<String, Integer>> updateFlightData(List<Map<String, Integer>> data, int targetAltitude, int maxChange) {
        List<Map<String, Integer>> newData = new ArrayList<>();
        for (Map<String, Integer> entry : data) {
            int altitude = entry.get("altitude");
            int adjustment = calculateAltitudeAdjustment(altitude, targetAltitude, maxChange);
            Map<String, Integer> newEntry = new HashMap<>();
            newEntry.put("time", entry.get("time"));
            newEntry.put("altitude", altitude + adjustment);
            newData.add(newEntry);
        }
        return newData;
    }

    public static void main(String[] args) {
        List<Map<String, Integer>> initialData = new ArrayList<>();
        Map<String, Integer> entry1 = new HashMap<>();
        entry1.put("time", 0);
        entry1.put("altitude", 10000);
        initialData.add(entry1);

        Map<String, Integer> entry2 = new HashMap<>();
        entry2.put("time", 1);
        entry2.put("altitude", 10200);
        initialData.add(entry2);

        Map<String, Integer> entry3 = new HashMap<>();
        entry3.put("time", 2);
        entry3.put("altitude", 10100);
        initialData.add(entry3);

        int targetAltitude = 10500;
        int maxChange = 300;
        List<Map<String, Integer>> updatedData = updateFlightData(initialData, targetAltitude, maxChange);
        for (Map<String, Integer> entry : updatedData) {
            System.out.println(entry);
        }
    }
}