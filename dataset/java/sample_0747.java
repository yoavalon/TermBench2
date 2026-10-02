import java.util.*;

public class sample_0747 {
    static int optimize_route(Map<String, List<Pair>> routes, Set<String> visited, String current, String destination, int cost) {
        if (current.equals(destination)) {
            return cost;
        }
        int min_cost = Integer.MAX_VALUE;
        for (Pair route : routes.get(current)) {
            if (!visited.contains(route.first)) {
                visited.add(route.first);
                int new_cost = optimize_route(routes, visited, route.first, destination, cost + route.second);
                visited.remove(route.first);
                if (new_cost < min_cost) {
                    min_cost = new_cost;
                }
            }
        }
        return min_cost;
    }

    static int find_optimal_path(Map<String, List<Pair>> routes, String start, String end) {
        Set<String> visited = new HashSet<>();
        visited.add(start);
        return optimize_route(routes, visited, start, end, 0);
    }

    public static void main(String[] args) {
        Map<String, List<Pair>> routes = new HashMap<>();
        routes.put("A", Arrays.asList(new Pair("B", 10), new Pair("C", 15)));
        routes.put("B", Arrays.asList(new Pair("C", 35), new Pair("D", 25)));
        routes.put("C", Arrays.asList(new Pair("D", 30)));
        routes.put("D", new ArrayList<>());

        String start = "A";
        String end = "D";
        System.out.println(find_optimal_path(routes, start, end));
    }
}

class Pair {
    String first;
    int second;

    Pair(String first, int second) {
        this.first = first;
        this.second = second;
    }
}