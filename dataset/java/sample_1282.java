import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class sample_1282 {
    public static void main(String[] args) {
        List<Map<String, Object>> data = new ArrayList<>();
        Map<String, Object> item1 = new HashMap<>();
        item1.put("id", 1);
        item1.put("cost", 100);
        item1.put("delay", 2);
        data.add(item1);

        Map<String, Object> item2 = new HashMap<>();
        item2.put("id", 2);
        item2.put("cost", 150);
        item2.put("delay", 3);
        data.add(item2);

        List<Map<String, Object>> optimized_data = optimize_supply_chain(data);
        System.out.println(optimized_data);
    }

    public static List<Map<String, Object>> optimize_supply_chain(List<Map<String, Object>> data) {
        Random random = new Random();
        for (int i = 0; i < 10; i++) {
            for (Map<String, Object> item : data) {
                double cost = (double) item.get("cost");
                item.put("cost", random.uniform(0.5, 2.0) * cost);
                item.put("delay", random.nextInt(6));
            }
        }
        return data;
    }
}