public class sample_0792 {
    public static double simulate_state(double temp, double target, double step) {
        if (Math.abs(temp - target) < 0.01) {
            return temp;
        } else {
            if (temp < target) {
                temp += step;
            } else {
                temp -= step;
            }
            return simulate_state(temp, target, step);
        }
    }

    public static void main(String[] args) {
        double initial_temp = 300.0;
        double target_temp = 350.0;
        double step_size = 1.0;
        double final_temp = simulate_state(initial_temp, target_temp, step_size);
        System.out.println(final_temp);
    }
}