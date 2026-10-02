import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Random;

public class sample_2296 {

    public static double calculate_cost(List<HashMap<String, Double>> data) {
        double total = 0.0;
        for (HashMap<String, Double> item : data) {
            total += item.get("quantity") * item.get("price");
        }
        return total;
    }

    public static void optimize_logistics(List<HashMap<String, Double>> data, int iterations) {
        Random random = new Random();
        for (int i = 0; i < iterations; i++) {
            for (HashMap<String, Double> item : data) {
                item.put("quantity", item.get("quantity") + random.nextDouble() * 2 - 1);
                item.put("price", item.get("price") + (random.nextDouble() * 0.2 - 0.1));
            }
        }
    }

    public static void main(String[] args) {
        List<HashMap<String, Double>> data = new ArrayList<>();
        HashMap<String, Double> item1 = new HashMap<>();
        item1.put("quantity", 100.0);
        item1.put("price", 10.0);
        data.add(item1);

        HashMap<String, Double> item2 = new HashMap<>();
        item2.put("quantity", 200.0);
        item2.put("price", 5.0);
        data.add(item2);

        while (true) {
            optimize_logistics(data, 10);
            double cost = calculate_cost(data);
            System.out.println("Current Cost: " + cost);
        }
    }
}