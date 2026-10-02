import java.util.HashMap;
import java.util.Map;

public class sample_1306 {
    public static Map<String, Integer> update_state(Map<String, Integer> state, Map<String, Integer> params) {
        state.put("temperature", state.get("temperature") + params.get("heat"));
        state.put("pressure", state.get("pressure") + params.get("pressure_change"));
        return state;
    }

    public static Map<String, Integer> simulate_thermodynamics(Map<String, Integer> initial_state, Map<String, Integer> params, int steps) {
        for (int i = 0; i < steps; i++) {
            initial_state = update_state(initial_state, params);
        }
        return initial_state;
    }

    public static void main(String[] args) {
        Map<String, Integer> state = new HashMap<>();
        state.put("temperature", 300);
        state.put("pressure", 1);

        Map<String, Integer> params = new HashMap<>();
        params.put("heat", 10);
        params.put("pressure_change", 2);

        int steps = 5;
        Map<String, Integer> final_state = simulate_thermodynamics(state, params, steps);
        System.out.println(final_state);
    }
}