import java.util.Arrays;

public class sample_0124 {

    static double compute_temperature_change(double energy, double mass, double specific_heat) {
        return energy / (mass * specific_heat);
    }

    static double update_boundary_conditions(double temp, double alpha, double dt) {
        return temp * (1 - alpha * dt);
    }

    static double simulate_thermodynamic_state(double initial_temp, double energy, double mass, double specific_heat, double alpha, double dt, int steps) {
        double temp = initial_temp;
        for (int i = 0; i < steps; i++) {
            double delta_temp = compute_temperature_change(energy, mass, specific_heat);
            temp += delta_temp;
            temp = update_boundary_conditions(temp, alpha, dt);
        }
        return temp;
    }

    public static void main(String[] args) {
        double initial_temp = 300;
        double energy = 1000;
        double mass = 50;
        double specific_heat = 0.5;
        double alpha = 0.01;
        double dt = 0.1;
        int steps = 100;
        double final_temp = simulate_thermodynamic_state(initial_temp, energy, mass, specific_heat, alpha, dt, steps);
        System.out.println(final_temp);
    }
}