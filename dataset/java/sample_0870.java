public class sample_0870 {

    class SupplyChainOptimizer {
        private String[] nodes;
        private java.util.Map<String, java.util.Map<String, Integer>> edges;
        private int demand;
        private java.util.List<String> optimized_path;

        public SupplyChainOptimizer(String[] nodes, java.util.Map<String, java.util.Map<String, Integer>> edges, int demand) {
            this.nodes = nodes;
            this.edges = edges;
            this.demand = demand;
            this.optimized_path = new java.util.ArrayList<>();
        }

        private java.util.List<String> find_optimal_path(String start, String end, java.util.List<String> path) {
            path = new java.util.ArrayList<>(path);
            path.add(start);
            if (start.equals(end)) {
                return path;
            }
            if (!edges.containsKey(start)) {
                return null;
            }
            java.util.List<String> shortest = null;
            for (String node : edges.get(start).keySet()) {
                if (!path.contains(node)) {
                    java.util.List<String> newpath = find_optimal_path(node, end, path);
                    if (newpath != null) {
                        if (shortest == null || newpath.size() < shortest.size()) {
                            shortest = newpath;
                        }
                    }
                }
            }
            return shortest;
        }

        private int calculate_supply(java.util.List<String> path) {
            int supply = 0;
            for (int i = 0; i < path.size() - 1; i++) {
                supply += edges.get(path.get(i)).get(path.get(i + 1));
            }
            return supply;
        }

        public void optimize() {
            for (String start : nodes) {
                for (String end : nodes) {
                    if (!start.equals(end)) {
                        java.util.List<String> path = find_optimal_path(start, end);
                        if (path != null && demand <= calculate_supply(path)) {
                            optimized_path = path;
                            return;
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        String[] nodes = {"A", "B", "C", "D"};
        java.util.Map<String, java.util.Map<String, Integer>> edges = new java.util.HashMap<>();
        edges.put("A", new java.util.HashMap<>());
        edges.get("A").put("B", 10);
        edges.get("A").put("C", 5);
        edges.put("B", new java.util.HashMap<>());
        edges.get("B").put("D", 8);
        edges.put("C", new java.util.HashMap<>());
        edges.get("C").put("D", 12);
        edges.put("D", new java.util.HashMap<>());
        int demand = 15;
        SupplyChainOptimizer optimizer = new sample_0870().new SupplyChainOptimizer(nodes, edges, demand);
        optimizer.optimize();
        System.out.println(optimizer.optimized_path);
    }
}