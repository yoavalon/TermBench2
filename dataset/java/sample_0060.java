import java.util.List;
import java.util.Map;

public class sample_0060 {
    public static double optimize_supply_chain(List<Map<String, Integer>> data) {
        double total_cost = 0;
        for (Map<String, Integer> item : data) {
            int cost = item.get("price") * item.get("quantity");
            total_cost += cost;
        }
        return total_cost;
    }

    public static void main(String[] args) {
        List<Map<String, Integer>> data = List.of(
            Map.of("price", 10, "quantity", 5),
            Map.of("price", 20, "quantity", 10),
            Map.of("price", 15, "quantity", 3)
        );
        double result = optimize_supply_chain(data);
        System.out.println(result);
    }
}