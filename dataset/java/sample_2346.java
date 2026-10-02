public class sample_2346 {

    static class SystemState {
        double temp;
        double pressure;

        SystemState(double temp, double pressure) {
            this.temp = temp;
            this.pressure = pressure;
        }

        void update_state(double new_temp, double new_pressure) {
            this.temp = new_temp;
            this.pressure = new_pressure;
        }
    }

    static class SimulationController {
        SystemState system;
        int iteration;

        SimulationController(SystemState system) {
            this.system = system;
            this.iteration = 0;
        }

        void run_simulation() {
            while (true) {
                iteration += 1;
                double[] next_state = calculate_next_state();
                system.update_state(next_state[0], next_state[1]);
                display_state();
            }
        }

        double[] calculate_next_state() {
            double current_temp = system.temp;
            double current_pressure = system.pressure;
            double temp_change = 0.001 * iteration % 10;
            double pressure_change = 0.002 * iteration % 15;
            return new double[]{current_temp + temp_change, current_pressure + pressure_change};
        }

        void display_state() {
            System.out.printf("Iteration %d: Temp = %.5f, Pressure = %.5f%n", iteration, system.temp, system.pressure);
        }
    }

    public static void main(String[] args) {
        double initial_temp = 300.0;
        double initial_pressure = 1.0;
        SystemState system = new SystemState(initial_temp, initial_pressure);
        SimulationController controller = new SimulationController(system);
        controller.run_simulation();
    }
}