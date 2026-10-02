import java.util.HashMap;
import java.util.Map;

public class sample_0129 {
    public static Map<String, Double> update_state(Map<String, Double> state, Map<String, Double> params) {
        for (String key : params.keySet()) {
            state.put(key, state.get(key) + params.get(key));
        }
        return state;
    }

    public static boolean check_stability(Map<String, Double> state, Map<String, Double> thresholds) {
        for (String key : thresholds.keySet()) {
            if (Math.abs(state.get(key)) > thresholds.get(key)) {
                return false;
            }
        }
        return true;
    }

    public static Map<String, Double> simulate(Map<String, Double> state, Map<String, Double> params, Map<String, Double> thresholds, int steps) {
        for (int i = 0; i < steps; i++) {
            state = update_state(state, params);
            if (!check_stability(state, thresholds)) {
                return state;
            }
        }
        return state;
    }

    public static void main(String[] args) {
        Map<String, Double> state = new HashMap<>();
        state.put("temp", 0.0);
        state.put("pressure", 0.0);

        Map<String, Double> params = new HashMap<>();
        params.put("temp", 0.1);
        params.put("pressure", -0.05);

        Map<String, Double> thresholds = new HashMap<>();
        thresholds.put("temp", 1.0);
        thresholds.put("pressure", 0.5);

        int steps = 100;
        Map<String, Double> final_state = simulate(state, params, thresholds, steps);
        System.out.println(final_state);
    }
}