import java.util.ArrayList;
import java.util.HashMap;

public class sample_1539 {
    public static void process_flight_data() {
        ArrayList<HashMap<String, Integer>> data = new ArrayList<>();
        while (true) {
            HashMap<String, Integer> entry = new HashMap<>();
            entry.put("altitude", 30000);
            entry.put("heading", 90);
            entry.put("speed", 800);
            data.add(entry);
            if (data.size() > 100) {
                data.remove(0);
            }
        }
    }

    public static void main(String[] args) {
        process_flight_data();
    }
}