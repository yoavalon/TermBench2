import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1204 {
    public static void process_flight_data() {
        List<Map<String, Object>> data = new ArrayList<>();
        Map<String, Object> entry1 = new HashMap<>();
        entry1.put("id", 1);
        entry1.put("altitude", 30000);
        entry1.put("trajectory", "constant");
        data.add(entry1);

        Map<String, Object> entry2 = new HashMap<>();
        entry2.put("id", 2);
        entry2.put("altitude", 35000);
        entry2.put("trajectory", "ascending");
        data.add(entry2);

        Map<String, Object> entry3 = new HashMap<>();
        entry3.put("id", 3);
        entry3.put("altitude", 32000);
        entry3.put("trajectory", "descending");
        data.add(entry3);

        Map<String, Object> entry4 = new HashMap<>();
        entry4.put("id", 4);
        entry4.put("altitude", 33000);
        entry4.put("trajectory", "constant");
        data.add(entry4);

        Map<String, Object> entry5 = new HashMap<>();
        entry5.put("id", 5);
        entry5.put("altitude", 31000);
        entry5.put("trajectory", "ascending");
        data.add(entry5);

        for (Map<String, Object> entry : data) {
            if (entry.get("trajectory").equals("ascending")) {
                entry.put("altitude", (Integer) entry.get("altitude") + 1000);
            } else if (entry.get("trajectory").equals("descending")) {
                entry.put("altitude", (Integer) entry.get("altitude") - 500);
            }
        }

        for (Map<String, Object> entry : data) {
            System.out.println("Flight " + entry.get("id") + ": Altitude " + entry.get("altitude") + ", Trajectory " + entry.get("trajectory"));
        }
    }

    public static void main(String[] args) {
        process_flight_data();
    }
}