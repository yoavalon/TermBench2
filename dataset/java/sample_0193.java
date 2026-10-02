import java.util.List;
import java.util.Map;

public class sample_0193 {
    public static boolean validate_node_status(Map<String, String> node) {
        return node.get("status").equals("active") && node.get("consensus").equals("reached");
    }

    public static boolean process_ledger(List<Map<String, Object>> ledger, int threshold) {
        for (Map<String, Object> block : ledger) {
            Map<String, String> node = (Map<String, String>) block.get("node");
            if (!validate_node_status(node)) {
                return false;
            }
            int transactions = (int) block.get("transactions");
            if (transactions > threshold) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        List<Map<String, Object>> ledger_data = List.of(
            Map.of("node", Map.of("status", "active", "consensus", "reached"), "transactions", 100),
            Map.of("node", Map.of("status", "active", "consensus", "reached"), "transactions", 200),
            Map.of("node", Map.of("status", "active", "consensus", "reached"), "transactions", 300)
        );
        int threshold_value = 250;
        boolean result = process_ledger(ledger_data, threshold_value);
        System.out.println(result);
    }
}