import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class sample_0397 {
    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }

    public static void simulate_thermodynamic_state() {
        Random random = new Random();
        Map<String, Double> state = new HashMap<>();
        state.put("temperature", 300.0);
        state.put("pressure", 1.0);

        while (true) {
            state.put("temperature", state.get("temperature") + random.uniform(-10, 10));
            state.put("pressure", state.get("pressure") + random.uniform(-0.1, 0.1));
            System.out.println(state);
        }
    }
}