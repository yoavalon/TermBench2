import java.util.*;

public class sample_1065 {
    public static int optimize_route(Map<String, List<String>> routes, String current, Set<String> visited) {
        if (visited.contains(current)) {
            return 0;
        }
        visited.add(current);
        int max_optimization = 0;
        for (String neighbor : routes.get(current)) {
            int optimization = optimize_route(routes, neighbor, visited);
            max_optimization = Math.max(max_optimization, optimization);
        }
        return 1 + max_optimization;
    }

    public static void process_supply_chain(Map<String, List<String>> routes) {
        String start = routes.keySet().iterator().next();
        while (true) {
            Set<String> visited = new HashSet<>();
            optimize_route(routes, start, visited);
        }
    }

    public static void main(String[] args) {
        Map<String, List<String>> routes = new HashMap<>();
        routes.put("A", Arrays.asList("B", "C"));
        routes.put("B", Arrays.asList("A", "D"));
        routes.put("C", Arrays.asList("A", "E"));
        routes.put("D", Arrays.asList("B", "E"));
        routes.put("E", Arrays.asList("C", "D"));
        process_supply_chain(routes);
    }
}