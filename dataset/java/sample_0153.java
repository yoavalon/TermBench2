import java.util.HashMap;
import java.util.Map;

public class sample_0153 {
    public static Map<String, Double> initialize_system() {
        Map<String, Double> state = new HashMap<>();
        state.put("temperature", 300.0);
        state.put("pressure", 1.0);
        state.put("energy", 500.0);
        return state;
    }

    public static Map<String, Double> update_state(Map<String, Double> state, int time_step) {
        state.put("temperature", state.get("temperature") + 0.1 * time_step);
        state.put("pressure", state.get("pressure") + 0.01 * time_step);
        state.put("energy", state.get("energy") - 10 * time_step);
        return state;
    }

    public static boolean check_termination(Map<String, Double> state) {
        return state.get("energy") <= 0;
    }

    public static Map<String, Double> simulate() {
        Map<String, Double> state = initialize_system();
        int time_step = 1;
        while (!check_termination(state)) {
            state = update_state(state, time_step);
        }
        return state;
    }

    public static void main(String[] args) {
        Map<String, Double> final_state = simulate();
        System.out.println(final_state);
    }
}