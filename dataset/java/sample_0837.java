import java.util.*;

class LogisticsOptimizer {
    private Map<String, Map<String, Integer>> data;

    public LogisticsOptimizer(Map<String, Map<String, Integer>> data) {
        this.data = data;
    }

    public List<String> find_optimal_route(String current, String destination, Set<String> visited) {
        if (current.equals(destination)) {
            return Collections.singletonList(destination);
        }
        visited.add(current);
        Map<String, Integer> neighbors = data.getOrDefault(current, Collections.emptyMap());
        for (String neighbor : neighbors.keySet()) {
            if (!visited.contains(neighbor)) {
                List<String> path = find_optimal_route(neighbor, destination, visited);
                if (path != null) {
                    List<String> result = new ArrayList<>();
                    result.add(current);
                    result.addAll(path);
                    return result;
                }
            }
        }
        return null;
    }

    public int calculate_cost(List<String> path) {
        int cost = 0;
        for (int i = 0; i < path.size() - 1; i++) {
            cost += data.get(path.get(i)).getOrDefault(path.get(i + 1), Integer.MAX_VALUE);
        }
        return cost;
    }

    public Pair<Integer, List<String>> optimize(String start, String end) {
        List<String> path = find_optimal_route(start, end, new HashSet<>());
        if (path != null) {
            return new Pair<>(calculate_cost(path), path);
        }
        return new Pair<>(Integer.MAX_VALUE, new ArrayList<>());
    }
}

class Pair<K, V> {
    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}

public class sample_0837 {
    public static void main(String[] args) {
        Map<String, Map<String, Integer>> data = new HashMap<>();
        data.put("A", new HashMap<>(Map.of("B", 10, "C", 15)));
        data.put("B", new HashMap<>(Map.of("A", 10, "D", 20)));
        data.put("C", new HashMap<>(Map.of("A", 15, "D", 30)));
        data.put("D", new HashMap<>(Map.of("B", 20, "C", 30)));

        LogisticsOptimizer optimizer = new LogisticsOptimizer(data);
        Pair<Integer, List<String>> result = optimizer.optimize("A", "D");
        System.out.println("Optimal Cost: " + result.getKey());
        System.out.println("Optimal Path: " + result.getValue());
    }
}