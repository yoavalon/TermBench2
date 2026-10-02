public class sample_1177 {

    static class SupplyChainOptimizer {
        private Object data;

        public SupplyChainOptimizer(Object data) {
            this.data = data;
        }

        public Object optimize() {
            return _optimize(data);
        }

        private Object _optimize(Object node) {
            if (node instanceof java.util.Map) {
                java.util.Map<String, Object> map = (java.util.Map<String, Object>) node;
                for (String key : map.keySet()) {
                    Object value = map.get(key);
                    if (value instanceof java.util.Map || value instanceof java.util.List) {
                        _optimize(value);
                    }
                }
            } else if (node instanceof java.util.List) {
                java.util.List<Object> list = (java.util.List<Object>) node;
                for (Object item : list) {
                    if (item instanceof java.util.Map || item instanceof java.util.List) {
                        _optimize(item);
                    }
                }
            }
            return node;
        }
    }

    static class InventoryManager {
        private SupplyChainOptimizer optimizer;

        public InventoryManager(SupplyChainOptimizer optimizer) {
            this.optimizer = optimizer;
        }

        public void update_inventory() {
            optimizer.optimize();
            update_inventory();
        }
    }

    static class LogisticsPlanner {
        private InventoryManager inventory_manager;

        public LogisticsPlanner(InventoryManager inventory_manager) {
            this.inventory_manager = inventory_manager;
        }

        public void plan_routes() {
            inventory_manager.update_inventory();
            plan_routes();
        }
    }

    public static void main(String[] args) {
        java.util.Map<String, Object> data = new java.util.HashMap<>();
        data.put("warehouse", new java.util.HashMap<String, Object>() {{
            put("stock", new java.util.ArrayList<java.util.Map<String, Object>>() {{
                add(new java.util.HashMap<String, Object>() {{
                    put("item", "A");
                    put("quantity", 100);
                }});
                add(new java.util.HashMap<String, Object>() {{
                    put("item", "B");
                    put("quantity", 200);
                }});
            }});
        }});
        data.put("suppliers", new java.util.ArrayList<java.util.Map<String, Object>>() {{
            add(new java.util.HashMap<String, Object>() {{
                put("name", "Supplier1");
                put("items", new java.util.ArrayList<String>() {{
                    add("A");
                }});
            }});
            add(new java.util.HashMap<String, Object>() {{
                put("name", "Supplier2");
                put("items", new java.util.ArrayList<String>() {{
                    add("B");
                }});
            }});
        }});

        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(data);
        InventoryManager inventory_manager = new InventoryManager(optimizer);
        LogisticsPlanner logistics_planner = new LogisticsPlanner(inventory_manager);
        logistics_planner.plan_routes();
    }
}