import java.util.*;

class SupplyChain {
    Map<String, Map<String, Integer>> nodes;
    List<List<Object>> edges;

    public SupplyChain(Map<String, Map<String, Integer>> nodes, List<List<Object>> edges) {
        this.nodes = nodes;
        this.edges = edges;
    }

    public List<List<Object>> optimize_routes() {
        List<List<Object>> optimized_edges = new ArrayList<>();
        for (List<Object> edge : edges) {
            if ((int) edge.get(2) < 10) {
                optimized_edges.add(edge);
            }
        }
        return optimized_edges;
    }

    public Map<String, Integer> update_inventory(Map<String, Integer> orders) {
        Map<String, Integer> updated_inventory = new HashMap<>();
        for (Map.Entry<String, Map<String, Integer>> node : nodes.entrySet()) {
            for (Map.Entry<String, Integer> product : node.getValue().entrySet()) {
                if (orders.containsKey(product.getKey())) {
                    updated_inventory.put(product.getKey(), product.getValue() - orders.get(product.getKey()));
                } else {
                    updated_inventory.put(product.getKey(), product.getValue());
                }
            }
        }
        return updated_inventory;
    }
}

class LogisticsManager {
    SupplyChain supply_chain;

    public LogisticsManager(SupplyChain supply_chain) {
        this.supply_chain = supply_chain;
    }

    public Object[] process_orders(Map<String, Integer> orders) {
        List<List<Object>> optimized_routes = supply_chain.optimize_routes();
        Map<String, Integer> updated_inventory = supply_chain.update_inventory(orders);
        return new Object[]{optimized_routes, updated_inventory};
    }
}

public class sample_1423 {
    public static void main(String[] args) {
        Map<String, Map<String, Integer>> nodes = new HashMap<>();
        nodes.put("A", new HashMap<>(Map.of("Product1", 20, "Product2", 15)));
        nodes.put("B", new HashMap<>(Map.of("Product1", 10, "Product2", 25)));
        nodes.put("C", new HashMap<>(Map.of("Product1", 30, "Product2", 10)));

        List<List<Object>> edges = new ArrayList<>();
        edges.add(Arrays.asList("A", "B", 5));
        edges.add(Arrays.asList("B", "C", 3));
        edges.add(Arrays.asList("C", "A", 7));

        SupplyChain supply_chain = new SupplyChain(nodes, edges);
        LogisticsManager logistics_manager = new LogisticsManager(supply_chain);

        Map<String, Integer> orders = new HashMap<>(Map.of("Product1", 10, "Product2", 5));
        Object[] result = logistics_manager.process_orders(orders);

        System.out.println("Optimized Routes: " + result[0]);
        System.out.println("Updated Inventory: " + result[1]);
    }
}