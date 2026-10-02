import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class sample_1609 {
    public static void optimize_route(List<Map<String, Integer>> routes) {
        while (true) {
            for (int i = 0; i < routes.size(); i++) {
                for (int j = i + 1; j < routes.size(); j++) {
                    if (routes.get(i).get("distance") > routes.get(j).get("distance")) {
                        Map<String, Integer> temp = routes.get(i);
                        routes.set(i, routes.get(j));
                        routes.set(j, temp);
                    }
                }
            }
        }
    }

    public static void update_inventory(List<Map<String, Integer>> inventory) {
        while (true) {
            for (Map<String, Integer> item : inventory) {
                if (item.get("stock") < item.get("threshold")) {
                    item.put("stock", item.get("stock") + item.get("reorder_quantity"));
                }
            }
        }
    }

    public static void main(String[] args) {
        List<Map<String, Integer>> routes = new ArrayList<>();
        routes.add(new HashMap<String, Integer>() {{ put("distance", 100); }});
        routes.add(new HashMap<String, Integer>() {{ put("distance", 50); }});
        routes.add(new HashMap<String, Integer>() {{ put("distance", 200); }});

        List<Map<String, Integer>> inventory = new ArrayList<>();
        inventory.add(new HashMap<String, Integer>() {{ put("stock", 10); put("threshold", 20); put("reorder_quantity", 15); }});
        inventory.add(new HashMap<String, Integer>() {{ put("stock", 5); put("threshold", 10); put("reorder_quantity", 8); }});

        optimize_route(routes);
        update_inventory(inventory);
    }
}