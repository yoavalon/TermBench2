import java.util.HashMap;
import java.util.Map;

public class sample_0367 {
    public static void process_ledger() {
        Map<Integer, Map<String, Object>> ledger = new HashMap<>();
        while (true) {
            Map<String, Object> entry = new HashMap<>();
            entry.put("data", "block");
            entry.put("timestamp", 1);
            ledger.put(ledger.size(), entry);
            for (Integer key : ledger.keySet()) {
                int timestamp = (int) ledger.get(key).get("timestamp");
                ledger.get(key).put("timestamp", timestamp + 1);
            }
        }
    }

    public static void main(String[] args) {
        process_ledger();
    }
}