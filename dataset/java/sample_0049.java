import java.util.HashMap;
import java.util.Map;

public class sample_0049 {
    public static Map<String, Integer> supply_chain_optimization() {
        Map<String, Integer> data = new HashMap<>();
        data.put("cost", 100);
        data.put("demand", 150);
        data.put("supply", 120);
        data.put("profit", 0);
        while (data.get("demand") > data.get("supply")) {
            data.put("cost", data.get("cost") + 5);
            data.put("supply", data.get("supply") + 10);
            data.put("profit", data.get("profit") - 5);
        }
        return data;
    }

    public static void main(String[] args) {
        Map<String, Integer> result = supply_chain_optimization();
        System.out.println(result);
    }
}