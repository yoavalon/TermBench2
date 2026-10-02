import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1308 {
    public static List<Map<String, Object>> optimize_inventory(Map<String, List<Integer>> data) {
        List<Integer> demand = data.get("demand");
        List<Integer> supply = data.get("supply");
        List<Map<String, Object>> mutations = new ArrayList<>();
        for (int i = 0; i < demand.size(); i++) {
            if (demand.get(i) > supply.get(i)) {
                Map<String, Object> mutation = new HashMap<>();
                mutation.put("type", "adjust_supply");
                mutation.put("index", i);
                mutation.put("new_value", demand.get(i));
                mutations.add(mutation);
            } else {
                Map<String, Object> mutation = new HashMap<>();
                mutation.put("type", "reduce_demand");
                mutation.put("index", i);
                mutation.put("new_value", supply.get(i));
                mutations.add(mutation);
            }
        }
        return mutations;
    }

    public static Map<String, List<Integer>> apply_mutations(Map<String, List<Integer>> data, List<Map<String, Object>> mutations) {
        for (Map<String, Object> mutation : mutations) {
            if (mutation.get("type").equals("adjust_supply")) {
                data.get("supply").set((int) mutation.get("index"), (int) mutation.get("new_value"));
            } else if (mutation.get("type").equals("reduce_demand")) {
                data.get("demand").set((int) mutation.get("index"), (int) mutation.get("new_value"));
            }
        }
        return data;
    }

    public static void main(String[] args) {
        Map<String, List<Integer>> initial_data = new HashMap<>();
        initial_data.put("demand", List.of(100, 200, 150, 300));
        initial_data.put("supply", List.of(120, 180, 160, 310));
        List<Map<String, Object>> mutations = optimize_inventory(initial_data);
        Map<String, List<Integer>> final_data = apply_mutations(initial_data, mutations);
        System.out.println(final_data);
    }
}