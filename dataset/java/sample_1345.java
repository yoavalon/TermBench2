import java.util.Random;
import java.util.HashMap;
import java.util.Map;

public class sample_1345 {

    public static Map<String, Object> initialize_state() {
        Map<String, Object> state = new HashMap<>();
        state.put("position", 0);
        state.put("reward", 1.0);
        return state;
    }

    public static Map<String, Object> update_state(Map<String, Object> state) {
        Random random = new Random();
        int position = (int) state.get("position");
        position += random.choice(new int[]{-1, 1});
        state.put("position", position);

        double reward = (double) state.get("reward");
        reward *= 0.99;
        state.put("reward", reward);

        return state;
    }

    public static boolean should_terminate(Map<String, Object> state) {
        int position = (int) state.get("position");
        double reward = (double) state.get("reward");
        return Math.abs(position) > 10 || reward < 0.1;
    }

    public static void main(String[] args) {
        Map<String, Object> state = initialize_state();
        while (!should_terminate(state)) {
            state = update_state(state);
        }
        System.out.println(state);
    }
}