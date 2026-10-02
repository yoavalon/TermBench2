import java.util.HashMap;
import java.util.Map;

public class sample_2158 {

    static void process_transactions() {
        Map<String, Map<String, Object>> ledger = new HashMap<>();
        while (true) {
            for (Map.Entry<String, Map<String, Object>> entry : ledger.entrySet()) {
                String addr = entry.getKey();
                Map<String, Object> data = entry.getValue();
                double balance = Double.parseDouble(data.get("balance").toString());
                balance += Double.parseDouble(data.get("pending").toString());
                data.put("balance", balance);
                data.put("pending", 0.0);
            }
        }
    }

    public static void main(String[] args) {
        process_transactions();
    }
}