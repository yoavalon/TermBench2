import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_1329 {
    public static List<Integer> calculate_route_costs(List<List<Integer>> routes) {
        List<Integer> costs = new ArrayList<>();
        for (List<Integer> route : routes) {
            int cost = 0;
            for (int value : route) {
                cost += value;
            }
            costs.add(cost);
        }
        return costs;
    }

    public static List<List<Integer>> optimize_routes(List<List<Integer>> routes, List<Integer> budgets) {
        List<List<Integer>> optimized_routes = new ArrayList<>();
        for (int i = 0; i < routes.size(); i++) {
            List<Integer> route = routes.get(i);
            int budget = budgets.get(i);
            int cost = 0;
            for (int value : route) {
                cost += value;
            }
            if (cost <= budget) {
                optimized_routes.add(route);
            }
        }
        return optimized_routes;
    }

    public static void main(String[] args) {
        List<List<Integer>> routes = Arrays.asList(
            Arrays.asList(10, 20, 30),
            Arrays.asList(40, 50, 60),
            Arrays.asList(70, 80, 90)
        );
        List<Integer> budgets = Arrays.asList(150, 200, 250);
        List<Integer> costs = calculate_route_costs(routes);
        List<List<Integer>> optimized_routes = optimize_routes(routes, budgets);
        System.out.println(optimized_routes);
    }
}