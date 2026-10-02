import java.util.List;
import java.util.Map;

public class sample_1840 {
    public static double optimize_supply_chain(List<Map<String, Double>> data) {
        double total_cost = 0.0;
        for (Map<String, Double> item : data) {
            total_cost += item.get("quantity") * item.get("price");
        }
        return Math.round(total_cost * 100.0) / 100.0;
    }

    public static void main(String[] args) {
        List<Map<String, Double>> data = List.of(
            Map.of("quantity", 150.75, "price", 2.34),
            Map.of("quantity", 200.5, "price", 1.8),
            Map.of("quantity", 120.25, "price", 3.15)
        );
        double result = optimize_supply_chain(data);
        System.out.println(result);
    }
}