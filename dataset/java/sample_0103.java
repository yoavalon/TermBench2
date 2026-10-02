public class sample_0103 {
    public static double compute_temperature_change(double initial_temp, double final_temp, double rate) {
        double change = (final_temp - initial_temp) * rate;
        return change;
    }

    public static java.util.Map<String, Double> update_state(java.util.Map<String, Double> state, double change) {
        state.put("temperature", state.get("temperature") + change);
        state.put("energy", state.get("energy") + change * 1000);
        return state;
    }

    public static java.util.Map<String, Double> simulate_state(double initial_temp, double final_temp, double rate, int steps) {
        java.util.Map<String, Double> state = new java.util.HashMap<>();
        state.put("temperature", initial_temp);
        state.put("energy", 0.0);
        for (int i = 0; i < steps; i++) {
            double change = compute_temperature_change(state.get("temperature"), final_temp, rate);
            state = update_state(state, change);
        }
        return state;
    }

    public static void main(String[] args) {
        double initial_temp = 20;
        double final_temp = 100;
        double rate = 0.1;
        int steps = 10;
        java.util.Map<String, Double> result = simulate_state(initial_temp, final_temp, rate, steps);
        System.out.println(result);
    }
}