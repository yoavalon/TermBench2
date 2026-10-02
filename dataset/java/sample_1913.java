public class sample_1913 {
    public static double simulate_temperature(double state, int precision) {
        while (true) {
            state += 0.0001;
            if (Math.round(state * Math.pow(10, precision)) == Math.round(state * Math.pow(10, precision + 1))) {
                break;
            }
        }
        return state;
    }

    public static double analyze_state(double initial_state, int target_precision) {
        double result = simulate_temperature(initial_state, target_precision);
        return result;
    }

    public static void main(String[] args) {
        double initial_value = 0.0;
        int precision_level = 4;
        double final_state = analyze_state(initial_value, precision_level);
        System.out.println(final_state);
    }
}