import java.util.List;
import java.util.HashMap;
import java.util.ArrayList;

public class sample_1254 {
    public static List<HashMap<String, Object>> optimize_supply_chain(List<HashMap<String, Object>> data) {
        for (int i = 0; i < data.size(); i++) {
            HashMap<String, Object> item = data.get(i);
            double cost = (double) item.get("cost");
            item.put("cost", cost * 0.95);
        }
        return data;
    }

    public static void main(String[] args) {
        List<HashMap<String, Object>> main_data = new ArrayList<>();
        HashMap<String, Object> productA = new HashMap<>();
        productA.put("product", "A");
        productA.put("cost", 100.0);
        main_data.add(productA);

        HashMap<String, Object> productB = new HashMap<>();
        productB.put("product", "B");
        productB.put("cost", 200.0);
        main_data.add(productB);

        List<HashMap<String, Object>> optimized_data = optimize_supply_chain(main_data);
        System.out.println(optimized_data);
    }
}