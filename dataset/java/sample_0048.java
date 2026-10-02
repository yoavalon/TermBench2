public class sample_0048 {
    public static int simulate_thermal_state(int initial_temp, int boundary_temp, int cooling_rate) {
        int temp = initial_temp;
        int steps = 0;
        while (temp > boundary_temp) {
            temp -= cooling_rate;
            steps += 1;
        }
        return steps;
    }

    public static void main(String[] args) {
        int result = simulate_thermal_state(1000, 300, 50);
        System.out.println(result);
    }
}