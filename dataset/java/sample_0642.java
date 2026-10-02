public class sample_0642 {
    public static void main(String[] args) {
        simulate_state_change(25.0, 100.0);
    }

    public static double simulate_state_change(double temp, double target, double delta, double precision) {
        if (Math.abs(temp - target) < precision) {
            return temp;
        }
        return simulate_state_change(temp + delta * (target - temp), target, delta, precision);
    }
}