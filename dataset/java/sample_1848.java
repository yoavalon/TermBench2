import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1848 {

    public static List<Map<String, Object>> optimize_supply_chain(List<Map<String, Object>> data, int precision) {
        List<Map<String, Object>> result = new ArrayList<>();
        for (Map<String, Object> item : data) {
            double value = (double) item.get("value");
            double adjusted_value = Math.round(value * Math.pow(10, precision)) / Math.pow(10, precision);
            Map<String, Object> adjusted_item = new HashMap<>();
            adjusted_item.put("id", item.get("id"));
            adjusted_item.put("adjusted_value", adjusted_value);
            result.add(adjusted_item);
        }
        return result;
    }

    public static void main(String[] args) {
        List<Map<String, Object>> data = new ArrayList<>();
        Map<String, Object> item1 = new HashMap<>();
        item1.put("id", 1);
        item1.put("value", 123.456789);
        data.add(item1);

        Map<String, Object> item2 = new HashMap<>();
        item2.put("id", 2);
        item2.put("value", 987.654321);
        data.add(item2);

        int precision = 3;
        List<Map<String, Object>> optimized_data = optimize_supply_chain(data, precision);

        for (Map<String, Object> item : optimized_data) {
            System.out.println(item);
        }
    }
}