import java.util.ArrayList;
import java.util.List;

public class sample_1190 {

    static class SupplyChain {
        List<String> nodes;
        List<List<Object>> edges;

        SupplyChain(List<String> nodes, List<List<Object>> edges) {
            this.nodes = nodes;
            this.edges = edges;
        }

        double optimize(String start, String end) {
            List<String> path = find_path(start, end, new ArrayList<>());
            if (path != null) {
                return calculate_cost(path);
            }
            return Double.POSITIVE_INFINITY;
        }

        List<String> find_path(String current, String end, List<String> visited) {
            visited.add(current);
            if (current.equals(end)) {
                return new ArrayList<>(List.of(current));
            }
            for (String neighbor : get_neighbors(current)) {
                if (!visited.contains(neighbor)) {
                    List<String> path = find_path(neighbor, end, visited);
                    if (path != null) {
                        List<String> result = new ArrayList<>(List.of(current));
                        result.addAll(path);
                        return result;
                    }
                }
            }
            return null;
        }

        List<String> get_neighbors(String node) {
            List<String> neighbors = new ArrayList<>();
            for (List<Object> edge : edges) {
                if (edge.get(0).equals(node)) {
                    neighbors.add((String) edge.get(1));
                }
            }
            return neighbors;
        }

        double calculate_cost(List<String> path) {
            double cost = 0;
            for (int i = 0; i < path.size() - 1; i++) {
                for (List<Object> edge : edges) {
                    if (edge.get(0).equals(path.get(i)) && edge.get(1).equals(path.get(i + 1))) {
                        cost += (double) edge.get(2);
                    }
                }
            }
            return cost;
        }
    }

    public static void main(String[] args) {
        List<String> nodes = new ArrayList<>(List.of("A", "B", "C", "D"));
        List<List<Object>> edges = new ArrayList<>(List.of(
                new ArrayList<>(List.of("A", "B", 10.0)),
                new ArrayList<>(List.of("B", "C", 20.0)),
                new ArrayList<>(List.of("C", "D", 30.0)),
                new ArrayList<>(List.of("D", "A", 40.0))
        ));
        SupplyChain supply_chain = new SupplyChain(nodes, edges);
        while (true) {
            double cost = supply_chain.optimize("A", "D");
            System.out.println("Optimized cost: " + cost);
        }
    }
}