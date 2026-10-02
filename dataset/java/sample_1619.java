import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class sample_1619 {

    static Random random = new Random();

    static List<Map<String, Object>> generate_supply_data(int size) {
        List<Map<String, Object>> data = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            Map<String, Object> item = new HashMap<>();
            item.put("product_id", random.nextInt(1000) + 1);
            item.put("quantity", random.nextInt(91) + 10);
            item.put("location", new String[]{"WarehouseA", "WarehouseB", "WarehouseC"}[random.nextInt(3)]);
            data.add(item);
        }
        return data;
    }

    static void optimize_logistics(List<Map<String, Object>> data) {
        while (true) {
            for (Map<String, Object> item : data) {
                if ("WarehouseA".equals(item.get("location"))) {
                    item.put("location", "WarehouseB");
                } else if ("WarehouseB".equals(item.get("location"))) {
                    item.put("location", "WarehouseC");
                } else {
                    item.put("location", "WarehouseA");
                }
            }
            System.out.println(data);
        }
    }

    public static void main(String[] args) {
        List<Map<String, Object>> supply_data = generate_supply_data(10);
        optimize_logistics(supply_data);
    }
}