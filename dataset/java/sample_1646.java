import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1646 {

    public static void update_consensus(Map<String, Object> node, List<Object> ledger, int threshold) {
        if (ledger.size() >= threshold) {
            node.put("consensus", true);
        } else {
            node.put("consensus", false);
        }
    }

    public static void process_transactions(List<Map<String, Object>> nodes, List<Object> ledger, int threshold) {
        for (Map<String, Object> node : nodes) {
            if ("active".equals(node.get("status"))) {
                ledger.add(node.get("transaction"));
                update_consensus(node, ledger, threshold);
            }
        }
    }

    public static void main(String[] args) {
        List<Map<String, Object>> nodes = new ArrayList<>();
        Map<String, Object> node1 = new HashMap<>();
        node1.put("status", "active");
        node1.put("transaction", "tx1");
        nodes.add(node1);

        Map<String, Object> node2 = new HashMap<>();
        node2.put("status", "inactive");
        node2.put("transaction", "tx2");
        nodes.add(node2);

        List<Object> ledger = new ArrayList<>();
        int threshold = 2;
        while (true) {
            process_transactions(nodes, ledger, threshold);
        }
    }
}