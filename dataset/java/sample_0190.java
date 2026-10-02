import java.util.*;

public class sample_0190 {
    public static int calculate_cost(List<String> route, Map<Pair<String, String>, Integer> costs) {
        int totalCost = 0;
        for (int i = 0; i < route.size() - 1; i++) {
            Pair<String, String> edge = new Pair<>(route.get(i), route.get(i + 1));
            totalCost += costs.getOrDefault(edge, 0);
        }
        return totalCost;
    }

    public static List<String> find_optimal_route(List<List<String>> routes, Map<Pair<String, String>, Integer> costs) {
        int minCost = Integer.MAX_VALUE;
        List<String> bestRoute = null;
        for (List<String> route : routes) {
            int cost = calculate_cost(route, costs);
            if (cost < minCost) {
                minCost = cost;
                bestRoute = route;
            }
        }
        return bestRoute;
    }

    public static void main(String[] args) {
        List<List<String>> routes = Arrays.asList(
            Arrays.asList("A", "B", "C"),
            Arrays.asList("A", "C", "B"),
            Arrays.asList("B", "A", "C")
        );

        Map<Pair<String, String>, Integer> costs = new HashMap<>();
        costs.put(new Pair<>("A", "B"), 10);
        costs.put(new Pair<>("B", "C"), 15);
        costs.put(new Pair<>("C", "A"), 20);

        List<String> optimalRoute = find_optimal_route(routes, costs);
        System.out.println(optimalRoute);
    }
}

class Pair<K, V> {
    private final K key;
    private final V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair<?, ?> pair = (Pair<?, ?>) o;
        return Objects.equals(key, pair.key) && Objects.equals(value, pair.value);
    }

    @Override
    public int hashCode() {
        return Objects.hash(key, value);
    }
}