import java.util.*;

public class sample_0132 {
    public static String validate_data(Map<String, Object> data) {
        String status = "invalid";
        if (data.containsKey("value") && data.containsKey("hash")) {
            if (data.get("hash").equals(hash_function(data.get("value")))) {
                status = "valid";
            }
        }
        return status;
    }

    public static int hash_function(Object value) {
        String valueStr = String.valueOf(value);
        int hash = 0;
        for (char c : valueStr.toCharArray()) {
            hash += (int) c;
        }
        return hash % 100;
    }

    public static List<String> process_data(List<Map<String, Object>> data_list) {
        List<String> results = new ArrayList<>();
        for (Map<String, Object> data : data_list) {
            String status = validate_data(data);
            results.add(status);
        }
        return results;
    }

    public static void main(String[] args) {
        List<Map<String, Object>> data_list = new ArrayList<>();
        Map<String, Object> data1 = new HashMap<>();
        data1.put("value", 123);
        data1.put("hash", 23);
        data_list.add(data1);

        Map<String, Object> data2 = new HashMap<>();
        data2.put("value", 456);
        data2.put("hash", 56);
        data_list.add(data2);

        List<String> processed_results = process_data(data_list);
        System.out.println(processed_results);
    }
}