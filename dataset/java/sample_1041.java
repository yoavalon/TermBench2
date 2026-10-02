import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class sample_1041 {
    public static int optimize_route(List<Object[]> routes, int current_cost) {
        if (routes.isEmpty()) {
            return current_cost;
        }
        Object[] next_route = routes.remove(0);
        int new_cost = current_cost + (int) next_route[1];
        return optimize_route(routes, new_cost);
    }

    public static void process_logistics(Map<String, Object> data) {
        if (data.isEmpty()) {
            return;
        }
        List<Object[]> routes = (List<Object[]>) data.get("routes");
        int total_cost = optimize_route(routes, 0);
        System.out.println(total_cost);
        process_logistics(data);
    }

    public static void main(String[] args) {
        Map<String, Object> data = new HashMap<>();
        List<Object[]> routes = new ArrayList<>();
        routes.add(new Object[]{"A", 10});
        routes.add(new Object[]{"B", 20});
        routes.add(new Object[]{"C", 30});
        data.put("routes", routes);
        process_logistics(data);
    }
}