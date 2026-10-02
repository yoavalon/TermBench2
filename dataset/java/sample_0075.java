import java.util.List;
import java.util.Map;

public class sample_0075 {
    public static void main(String[] args) {
        Map<String, Object> data = Map.of(
            "distances", Map.of(
                "A", Map.of("B", 10, "C", 15),
                "B", Map.of("A", 10, "C", 35),
                "C", Map.of("A", 15, "B", 35)
            ),
            "routes", List.of(
                List.of("A", "B", "C"),
                List.of("A", "C", "B")
            )
        );
        optimize_supply_chain(data);
    }

    public static List<String> optimize_supply_chain(Map<String, Object> data) {
        List<List<String>> routes = (List<List<String>>) data.get("routes");
        List<String> best_route = find_best_route(routes);
        return best_route;
    }

    private static int calculate_cost(List<String> route, Map<String, Map<String, Integer>> distances) {
        int cost = 0;
        for (int i = 0; i < route.size() - 1; i++) {
            cost += distances.get(route.get(i)).get(route.get(i + 1));
        }
        return cost;
    }

    private static List<String> find_best_route(List<List<String>> routes) {
        List<String> best_route = null;
        int min_cost = Integer.MAX_VALUE;
        Map<String, Map<String, Integer>> distances = (Map<String, Map<String, Integer>>) routes.get(0).get(0);
        for (List<String> route : routes) {
            int cost = calculate_cost(route, distances);
            if (cost < min_cost) {
                min_cost = cost;
                best_route = route;
            }
        }
        return best_route;
    }
}