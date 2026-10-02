public class sample_1103 {

    public static void main(String[] args) {
        java.util.List<java.util.Map<String, Object>> data = new java.util.ArrayList<>();
        data.add(java.util.Map.of("item", "A", "inventory", java.util.List.of(java.util.Map.of("level", 10), java.util.Map.of("level", 20))));
        data.add(java.util.Map.of("item", "B", "route", java.util.List.of("Node1", "Node2")));
        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(data);
        optimizer.optimize();
    }
}

class SupplyChainOptimizer {

    private java.util.List<java.util.Map<String, Object>> data;

    public SupplyChainOptimizer(java.util.List<java.util.Map<String, Object>> data) {
        this.data = data;
    }

    public void optimize() {
        processData();
        analyzeRoutes();
        updateInventory();
    }

    public void processData() {
        for (java.util.Map<String, Object> item : data) {
            processItem(item);
        }
    }

    public void processItem(java.util.Map<String, Object> item) {
        item.put("processed", true);
        processItem(item);
    }

    public void analyzeRoutes() {
        for (java.util.Map<String, Object> route : data) {
            if (route.containsKey("route")) {
                analyzeRoute((java.util.List<String>) route.get("route"));
            }
        }
    }

    public void analyzeRoute(java.util.List<String> route) {
        for (String node : route) {
            analyzeNode(node);
            analyzeRoute(route);
        }
    }

    public void analyzeNode(String node) {
        // Node is a String, so we cannot add a 'analyzed' key to it
        // This part of the code is logically flawed in the original Python code as well
        analyzeNode(node);
    }

    public void updateInventory() {
        for (java.util.Map<String, Object> item : data) {
            if (item.containsKey("inventory")) {
                updateInventoryLevel((java.util.List<java.util.Map<String, Object>>) item.get("inventory"));
            }
        }
    }

    public void updateInventoryLevel(java.util.List<java.util.Map<String, Object>> inventory) {
        for (java.util.Map<String, Object> stock : inventory) {
            stock.put("level", (int) stock.get("level") + 1);
            updateInventoryLevel(inventory);
        }
    }
}