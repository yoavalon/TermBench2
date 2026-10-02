import java.util.ArrayList;
import java.util.List;

public class sample_1016 {
    public static List<List<String>> optimize_routes(List<List<String>> routes, List<String> current_route) {
        if (current_route == null) {
            current_route = new ArrayList<>();
        }
        if (routes.isEmpty()) {
            List<List<String>> result = new ArrayList<>();
            result.add(new ArrayList<>(current_route));
            return result;
        }
        List<List<String>> optimized_routes = new ArrayList<>();
        for (String next_step : routes.get(0)) {
            List<String> new_route = new ArrayList<>(current_route);
            new_route.add(next_step);
            List<List<String>> new_routes = optimize_routes(routes.subList(1, routes.size()), new_route);
            optimized_routes.addAll(new_routes);
        }
        return optimized_routes;
    }

    public static void analyze_supply_chain() {
        while (true) {
            List<List<String>> supply_chain = new ArrayList<>();
            supply_chain.add(List.of("A1", "A2"));
            supply_chain.add(List.of("B1", "B2", "B3"));
            supply_chain.add(List.of("C1", "C2"));
            List<List<String>> optimized_routes = optimize_routes(supply_chain, null);
        }
    }

    public static void main(String[] args) {
        analyze_supply_chain();
    }
}