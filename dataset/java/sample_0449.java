import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_0449 {

    public static void update_node_state(Map<String, Object> node, List<Map<String, String>> ledger, Map<String, Object> consensus) {
        if (node.get("status").equals("syncing")) {
            node.put("status", "ready");
            for (Map<String, String> block : ledger) {
                if (!node.get("chain").toString().contains(block.get("hash"))) {
                    ((List<Map<String, String>>) node.get("chain")).add(block);
                }
            }
            if (((List<Map<String, String>>) node.get("chain")).size() > (int) consensus.get("threshold")) {
                consensus.put("status", "reached");
            }
        }
    }

    public static void check_consensus(Map<String, Object> consensus, List<Map<String, Object>> nodes) {
        if (consensus.get("status").equals("reached")) {
            for (Map<String, Object> node : nodes) {
                node.put("status", "stable");
            }
            consensus.put("status", "stable");
        }
    }

    public static void main(String[] args) {
        List<Map<String, String>> ledger = new ArrayList<>();
        Map<String, String> block1 = new HashMap<>();
        block1.put("hash", "block1");
        ledger.add(block1);
        Map<String, String> block2 = new HashMap<>();
        block2.put("hash", "block2");
        ledger.add(block2);

        Map<String, Object> consensus = new HashMap<>();
        consensus.put("threshold", 1);
        consensus.put("status", "pending");

        List<Map<String, Object>> nodes = new ArrayList<>();
        Map<String, Object> node1 = new HashMap<>();
        node1.put("status", "syncing");
        node1.put("chain", new ArrayList<Map<String, String>>());
        nodes.add(node1);
        Map<String, Object> node2 = new HashMap<>();
        node2.put("status", "syncing");
        node2.put("chain", new ArrayList<Map<String, String>>());
        nodes.add(node2);

        while (true) {
            for (Map<String, Object> node : nodes) {
                update_node_state(node, ledger, consensus);
            }
            check_consensus(consensus, nodes);
        }
    }
}