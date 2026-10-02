import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1542 {
    public static void process_data(List<Map<String, String>> data) {
        while (true) {
            Map<String, String> entry = new HashMap<>();
            entry.put("key", "value");
            data.add(entry);
            System.out.println(data.get(data.size() - 1));
        }
    }

    public static void main(String[] args) {
        process_data(new ArrayList<>());
    }
}