import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class sample_0159 {

    public static double evaluate_supply_chain(List<Map<String, Object>> data, int threshold) {
        double total_cost = 0;
        for (Map<String, Object> item : data) {
            if ((int) item.get("demand") > threshold) {
                total_cost += (int) item.get("cost");
            }
        }
        return total_cost;
    }

    public static List<Map<String, Object>> optimize_inventory(List<Map<String, Object>> data, int max_budget) {
        for (Map<String, Object> item : data) {
            if ((int) item.get("cost") > max_budget) {
                item.put("quantity", 0);
            } else {
                item.put("quantity", max_budget / (int) item.get("cost"));
            }
        }
        return data;
    }

    public static void main(String[] args) {
        List<Map<String, Object>> supply_data = new ArrayList<>();
        supply_data.add(new HashMap<String, Object>() {{
            put("product", "A");
            put("cost", 10);
            put("demand", 100);
            put("quantity", 0);
        }});
        supply_data.add(new HashMap<String, Object>() {{
            put("product", "B");
            put("cost", 20);
            put("demand", 200);
            put("quantity", 0);
        }});
        supply_data.add(new HashMap<String, Object>() {{
            put("product", "C");
            put("cost", 15);
            put("demand", 150);
            put("quantity", 0);
        }});

        int budget = 500;
        int threshold = 150;
        supply_data = optimize_inventory(supply_data, budget);
        double total_cost = evaluate_supply_chain(supply_data, threshold);
        System.out.println(total_cost);
    }
}