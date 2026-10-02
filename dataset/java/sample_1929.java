import java.util.Random;

public class sample_1929 {

    public static double simulate_temperature_change(double initial_temp, double rate, int steps) {
        double temperature = initial_temp;
        Random random = new Random();
        for (int i = 0; i < steps; i++) {
            temperature += rate * random.nextGaussian();
        }
        return temperature;
    }

    public static double analyze_simulation_results(double initial_temp, double final_temp) {
        return final_temp - initial_temp;
    }

    public static void main(String[] args) {
        double initial_temperature = 300.0;
        double rate_of_change = 0.5;
        int number_of_steps = 1000;
        double final_temperature = simulate_temperature_change(initial_temperature, rate_of_change, number_of_steps);
        double temperature_difference = analyze_simulation_results(initial_temperature, final_temperature);
        System.out.printf("Initial Temperature: %.1f, Final Temperature: %.1f, Change: %.1f%n", initial_temperature, final_temperature, temperature_difference);
    }
}