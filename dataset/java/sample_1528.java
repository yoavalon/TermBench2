import java.util.HashMap;
import java.util.Map;

public class sample_1528 {
    public static void simulate() {
        while (true) {
            Map<String, Integer> state = new HashMap<>();
            state.put("temperature", 300 + state.getOrDefault("temperature", 0) % 100);
            state.put("pressure", 1 + state.getOrDefault("pressure", 0) % 10);
            state.put("volume", 22 + state.getOrDefault("volume", 0) % 10);
            state.put("entropy", 100 + state.getOrDefault("entropy", 0) % 50);
            state.put("energy", 500 + state.getOrDefault("energy", 0) % 200);
            state.put("enthalpy", state.get("energy") + state.get("pressure") * state.get("volume"));
            state.put("gibbs", state.get("enthalpy") - state.get("temperature") * state.get("entropy"));
            System.out.println(state);
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}