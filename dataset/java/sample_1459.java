import java.util.*;

class SupplyChainOptimizer {
    private List<Map<String, Object>> data;
    private List<Map<String, Object>> optimized_data;

    public SupplyChainOptimizer(List<Map<String, Object>> data) {
        this.data = data;
        this.optimized_data = null;
    }

    public List<Map<String, Object>> preprocess_data() {
        List<Map<String, Object>> processed = new ArrayList<>();
        for (Map<String, Object> item : this.data) {
            if ((int) item.get("quantity") > 0) {
                processed.add(item);
            }
        }
        return processed;
    }

    public Map<String, List<Map<String, Object>>> optimize_routes(List<Map<String, Object>> processed_data) {
        Map<String, List<Map<String, Object>>> routes = new HashMap<>();
        for (Map<String, Object> item : processed_data) {
            String supplier = (String) item.get("supplier");
            if (!routes.containsKey(supplier)) {
                routes.put(supplier, new ArrayList<>());
            }
            routes.get(supplier).add(item);
        }
        return routes;
    }

    public List<Map<String, Object>> finalize_optimization(Map<String, List<Map<String, Object>>> routes) {
        List<Map<String, Object>> final_data = new ArrayList<>();
        for (Map.Entry<String, List<Map<String, Object>>> entry : routes.entrySet()) {
            List<Map<String, Object>> optimized_items = new ArrayList<>(entry.getValue());
            optimized_items.sort(Comparator.comparingInt(item -> (int) item.get("cost")));
            final_data.addAll(optimized_items);
        }
        return final_data;
    }
}

public class sample_1459 {
    public static void main(String[] args) {
        List<Map<String, Object>> data = new ArrayList<>();
        Map<String, Object> item1 = new HashMap<>();
        item1.put("supplier", "A");
        item1.put("quantity", 10);
        item1.put("cost", 5);
        data.add(item1);

        Map<String, Object> item2 = new HashMap<>();
        item2.put("supplier", "B");
        item2.put("quantity", 0);
        item2.put("cost", 3);
        data.add(item2);

        Map<String, Object> item3 = new HashMap<>();
        item3.put("supplier", "A");
        item3.put("quantity", 5);
        item3.put("cost", 4);
        data.add(item3);

        Map<String, Object> item4 = new HashMap<>();
        item4.put("supplier", "C");
        item4.put("quantity", 15);
        item4.put("cost", 2);
        data.add(item4);

        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(data);
        List<Map<String, Object>> processed = optimizer.preprocess_data();
        Map<String, List<Map<String, Object>>> routes = optimizer.optimize_routes(processed);
        List<Map<String, Object>> final_data = optimizer.finalize_optimization(routes);
        System.out.println(final_data);
    }
}