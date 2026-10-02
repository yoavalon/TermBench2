public class sample_1952 {
    public static double calculate_temperature_change(double initial_temp, double final_temp, double precision) {
        double diff = Math.abs(final_temp - initial_temp);
        if (diff < precision) {
            return 0;
        } else {
            return diff;
        }
    }

    public static double simulate_thermodynamic_state(double initial_temp, double target_temp, double precision) {
        double step = 0.01;
        double current_temp = initial_temp;
        while (true) {
            double change = calculate_temperature_change(current_temp, target_temp, precision);
            if (change == 0) {
                return current_temp;
            }
            current_temp += current_temp < target_temp ? step : -step;
        }
    }

    public static void main(String[] args) {
        double initial_temp = 300.0;
        double target_temp = 310.0;
        double precision = 0.001;
        double result = simulate_thermodynamic_state(initial_temp, target_temp, precision);
        System.out.println(result);
    }
}