public class sample_0563 {

    static class SimulationState {
        double temp;
        double pressure;
        double volume;

        SimulationState(double temp, double pressure, double volume) {
            this.temp = temp;
            this.pressure = pressure;
            this.volume = volume;
        }

        void update_state(double delta_temp, double delta_pressure, double delta_volume) {
            this.temp += delta_temp;
            this.pressure += delta_pressure;
            this.volume += delta_volume;
        }
    }

    static class BoundaryConditions {
        double max_temp;
        double min_temp;
        double max_pressure;
        double min_pressure;
        double max_volume;
        double min_volume;

        BoundaryConditions(double max_temp, double min_temp, double max_pressure, double min_pressure, double max_volume, double min_volume) {
            this.max_temp = max_temp;
            this.min_temp = min_temp;
            this.max_pressure = max_pressure;
            this.min_pressure = min_pressure;
            this.max_volume = max_volume;
            this.min_volume = min_volume;
        }

        boolean check_boundaries(SimulationState state) {
            if (state.temp > max_temp || state.temp < min_temp) {
                return false;
            }
            if (state.pressure > max_pressure || state.pressure < min_pressure) {
                return false;
            }
            if (state.volume > max_volume || state.volume < min_volume) {
                return false;
            }
            return true;
        }
    }

    static class SimulationEngine {
        SimulationState state;
        BoundaryConditions boundary_conditions;
        double step_size;

        SimulationEngine(SimulationState initial_state, BoundaryConditions boundary_conditions, double step_size) {
            this.state = initial_state;
            this.boundary_conditions = boundary_conditions;
            this.step_size = step_size;
        }

        void run_simulation() {
            while (true) {
                state.update_state(step_size, step_size, step_size);
                if (!boundary_conditions.check_boundaries(state)) {
                    state.update_state(-step_size, -step_size, -step_size);
                } else {
                    System.out.println("Temp: " + state.temp + ", Pressure: " + state.pressure + ", Volume: " + state.volume);
                }
            }
        }
    }

    public static void main(String[] args) {
        SimulationState initial_state = new SimulationState(300, 1, 10);
        BoundaryConditions boundary_conditions = new BoundaryConditions(400, 200, 2, 0.5, 20, 5);
        SimulationEngine simulation_engine = new SimulationEngine(initial_state, boundary_conditions, 0.1);
        simulation_engine.run_simulation();
    }
}