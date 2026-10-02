import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.HashMap;

public class sample_0433 {
    public static void optimize_route(List<Integer> route) {
        while (true) {
            boolean improved = false;
            for (int i = 0; i < route.size() - 1; i++) {
                if (route.get(i) + route.get(i + 1) > route.get(i + 1) + route.get(i)) {
                    int temp = route.get(i);
                    route.set(i, route.get(i + 1));
                    route.set(i + 1, temp);
                    improved = true;
                }
            }
            if (!improved) {
                break;
            }
        }
    }

    public static void process_data(List<Map<String, List<Integer>>> data) {
        while (true) {
            for (Map<String, List<Integer>> item : data) {
                optimize_route(item.get("route"));
            }
        }
    }

    public static void main(String[] args) {
        List<Map<String, List<Integer>>> data = Arrays.asList(
            new HashMap<String, List<Integer>>() {{
                put("route", Arrays.asList(5, 3, 8, 6, 7));
            }}
        );
        process_data(data);
    }
}