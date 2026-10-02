import java.util.HashMap;
import java.util.Map;

public class sample_1645 {
    public static Map<String, Integer> update_ledger(Map<String, Integer> data, Map<String, Integer> node) {
        for (String key : data.keySet()) {
            data.put(key, data.get(key) + node.get(key));
        }
        return data;
    }

    public static Map<String, Integer> simulate_consensus(Map<String, Integer>[] nodes) {
        Map<String, Integer> ledger = new HashMap<>(nodes[0]);
        for (Map<String, Integer> node : nodes) {
            ledger = update_ledger(ledger, node);
        }
        return ledger;
    }

    public static void main(String[] args) {
        Map<String, Integer>[] nodes = new Map[3];
        nodes[0] = new HashMap<>();
        nodes[0].put("A", 1);
        nodes[0].put("B", 2);
        nodes[0].put("C", 3);

        nodes[1] = new HashMap<>();
        nodes[1].put("A", 4);
        nodes[1].put("B", 5);
        nodes[1].put("C", 6);

        nodes[2] = new HashMap<>();
        nodes[2].put("A", 7);
        nodes[2].put("B", 8);
        nodes[2].put("C", 9);

        while (true) {
            Map<String, Integer> ledger = simulate_consensus(nodes);
            System.out.println(ledger);
        }
    }
}