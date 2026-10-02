public class sample_0116 {
    public static double calculate_energy(java.util.Map<String, Double> state, java.util.Map<String, Double> boundary) {
        double energy = 0;
        for (String key : state.keySet()) {
            energy += state.get(key) * boundary.get(key);
        }
        return energy;
    }

    public static boolean check_condition(double energy, double threshold) {
        if (energy > threshold) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        java.util.Map<String, Double> state = new java.util.HashMap<>();
        state.put("temperature", 300.0);
        state.put("pressure", 101325.0);
        state.put("volume", 0.0224);

        java.util.Map<String, Double> boundary = new java.util.HashMap<>();
        boundary.put("temperature", 0.001);
        boundary.put("pressure", -0.0001);
        boundary.put("volume", 0.001);

        double threshold = 500;
        double energy = calculate_energy(state, boundary);
        boolean condition_met = check_condition(energy, threshold);
        if (condition_met) {
            System.out.println("Condition met: " + energy);
        } else {
            System.out.println("Condition not met: " + energy);
        }
    }
}