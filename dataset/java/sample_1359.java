import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class sample_1359 {

    static Random random = new Random();

    static List<Map<String, Integer>> generate_shipments(List<Map<String, Integer>> data) {
        List<Map<String, Integer>> mutated_data = new ArrayList<>();
        for (Map<String, Integer> item : data) {
            Map<String, Integer> new_item = new HashMap<>(item);
            new_item.put("quantity", (int) (new_item.get("quantity") * random.uniform(0.8, 1.2)));
            new_item.put("lead_time", (int) (new_item.get("lead_time") * random.uniform(0.9, 1.1)));
            mutated_data.add(new_item);
        }
        return mutated_data;
    }

    static List<Map<String, Integer>> optimize_inventory(List<Map<String, Integer>> data) {
        List<Map<String, Integer>> optimized_data = new ArrayList<>();
        for (Map<String, Integer> item : data) {
            if (item.get("quantity") > 100) {
                item.put("quantity", 100);
            }
            if (item.get("lead_time") < 5) {
                item.put("lead_time", 5);
            }
            optimized_data.add(item);
        }
        return optimized_data;
    }

    public static void main(String[] args) {
        List<Map<String, Integer>> initial_data = new ArrayList<>();
        Map<String, Integer> itemA = new HashMap<>();
        itemA.put("item", 1);
        itemA.put("quantity", 120);
        itemA.put("lead_time", 4);
        initial_data.add(itemA);

        Map<String, Integer> itemB = new HashMap<>();
        itemB.put("item", 2);
        itemB.put("quantity", 90);
        itemB.put("lead_time", 6);
        initial_data.add(itemB);

        Map<String, Integer> itemC = new HashMap<>();
        itemC.put("item", 3);
        itemC.put("quantity", 150);
        itemC.put("lead_time", 3);
        initial_data.add(itemC);

        List<Map<String, Integer>> mutated_data = generate_shipments(initial_data);
        List<Map<String, Integer>> optimized_data = optimize_inventory(mutated_data);
        System.out.println(optimized_data);
    }
}