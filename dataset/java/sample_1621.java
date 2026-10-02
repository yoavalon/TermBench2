import java.util.HashMap;
import java.util.Map;

public class sample_1621 {
    public static Map<String, Double> update_state(Map<String, Double> state, Map<String, Double> delta) {
        Map<String, Double> new_state = new HashMap<>();
        for (String key : state.keySet()) {
            new_state.put(key, state.get(key) + delta.get(key));
        }
        return new_state;
    }

    public static void simulate_system(Map<String, Double> initial_state, Map<String, Map<String, Double>> deltas) {
        Map<String, Double> current_state = initial_state;
        while (true) {
            for (Map<String, Double> delta : deltas) {
                current_state = update_state(current_state, delta);
            }
        }
    }

    public static void main(String[] args) {
        Map<String, Double> initial_state = new HashMap<>();
        initial_state.put("temperature", 300.0);
        initial_state.put("pressure", 1.0);

        Map<String, Map<String, Double>> deltas = new HashMap<>();
        Map<String, Double> delta1 = new HashMap<>();
        delta1.put("temperature", 10.0);
        delta1.put("pressure", -0.5);
        deltas.put("delta1", delta1);

        Map<String, Double> delta2 = new HashMap<>();
        delta2.put("temperature", -5.0);
        delta2.put("pressure", 0.25);
        deltas.put("delta2", delta2);

        simulate_system(initial_state, deltas);
    }
}