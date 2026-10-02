import java.util.ArrayList;
import java.util.List;

public class sample_1387 {
    public static int optimize_route(List<List<Integer>> routes, List<Integer> demands) {
        List<Integer> costs = new ArrayList<>();
        for (List<Integer> r : routes) {
            int cost = 0;
            for (int i = 0; i < demands.size(); i++) {
                cost += demands.get(i) * r.get(i);
            }
            costs.add(cost);
        }
        return costs.stream().min(Integer::compare).get();
    }

    public static List<Integer> update_demands(List<Integer> demands, List<Integer> adjustments) {
        List<Integer> updated_demands = new ArrayList<>();
        for (int i = 0; i < demands.size(); i++) {
            updated_demands.add(demands.get(i) + adjustments.get(i));
        }
        return updated_demands;
    }

    public static void main(String[] args) {
        List<List<Integer>> routes = new ArrayList<>();
        routes.add(List.of(2, 3, 1));
        routes.add(List.of(4, 1, 2));
        routes.add(List.of(3, 2, 3));
        List<Integer> demands = List.of(5, 10, 15);
        List<Integer> adjustments = List.of(-1, 2, -3);
        List<Integer> updated_demands = update_demands(demands, adjustments);
        int best_cost = optimize_route(routes, updated_demands);
        System.out.println(best_cost);
    }
}