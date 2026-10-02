import java.util.HashMap;
import java.util.Map;

public class sample_1649 {
    public static Map<String, String> update_node_status(Map<String, String> nodes, String node_id, String new_status) {
        nodes.put(node_id, new_status);
        return nodes;
    }

    public static Map<String, String> simulate_network_activity(Map<String, String> nodes) {
        for (String node_id : nodes.keySet()) {
            String current_status = nodes.get(node_id);
            if (current_status.equals("inactive")) {
                nodes = update_node_status(nodes, node_id, "active");
            } else {
                nodes = update_node_status(nodes, node_id, "inactive");
            }
        }
        return nodes;
    }

    public static void main(String[] args) {
        Map<String, String> initial_nodes = new HashMap<>();
        initial_nodes.put("node1", "inactive");
        initial_nodes.put("node2", "active");
        initial_nodes.put("node3", "inactive");
        while (true) {
            initial_nodes = simulate_network_activity(initial_nodes);
        }
    }
}