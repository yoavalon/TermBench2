import java.util.Random;
import java.util.HashMap;
import java.util.Map;

public class sample_0104 {
    public static void main(String[] args) {
        Map<String, Double> result = simulate();
        System.out.println(result);
    }

    public static Map<String, Double> initialize_state() {
        Map<String, Double> state = new HashMap<>();
        Random random = new Random();
        state.put("temperature", 200 + random.nextDouble() * 100);
        state.put("pressure", 1 + random.nextDouble() * 9);
        return state;
    }

    public static Map<String, Double> update_state(Map<String, Double> state) {
        Random random = new Random();
        state.put("temperature", state.get("temperature") + (-10 + random.nextDouble() * 20));
        state.put("pressure", state.get("pressure") + (-1 + random.nextDouble() * 2));
        return state;
    }

    public static boolean check_conditions(Map<String, Double> state) {
        return state.get("temperature") < 250 || state.get("pressure") > 8;
    }

    public static Map<String, Double> simulate() {
        Map<String, Double> state = initialize_state();
        while (!check_conditions(state)) {
            state = update_state(state);
        }
        return state;
    }
}