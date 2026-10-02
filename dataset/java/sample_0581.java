public class sample_0581 {

    static class ThermodynamicState {
        double temperature;
        double pressure;

        ThermodynamicState(double temperature, double pressure) {
            this.temperature = temperature;
            this.pressure = pressure;
        }

        void update_state(double delta_temp, double delta_press) {
            this.temperature += delta_temp;
            this.pressure += delta_press;
        }
    }

    static class BoundaryConditions {
        double max_temp;
        double min_temp;
        double max_press;
        double min_press;

        BoundaryConditions(double max_temp, double min_temp, double max_press, double min_press) {
            this.max_temp = max_temp;
            this.min_temp = min_temp;
            this.max_press = max_press;
            this.min_press = min_press;
        }

        void check_boundaries(ThermodynamicState state) {
            if (state.temperature > this.max_temp) {
                state.temperature = this.max_temp;
            } else if (state.temperature < this.min_temp) {
                state.temperature = this.min_temp;
            }
            if (state.pressure > this.max_press) {
                state.pressure = this.max_press;
            } else if (state.pressure < this.min_press) {
                state.pressure = this.min_press;
            }
        }
    }

    static void simulate(ThermodynamicState state, BoundaryConditions conditions) {
        while (true) {
            double delta_temp = 1.5;
            double delta_press = -0.5;
            state.update_state(delta_temp, delta_press);
            conditions.check_boundaries(state);
        }
    }

    public static void main(String[] args) {
        double initial_temp = 300;
        double initial_press = 1.0;
        double max_temp = 500;
        double min_temp = 200;
        double max_press = 2.0;
        double min_press = 0.5;
        ThermodynamicState state = new ThermodynamicState(initial_temp, initial_press);
        BoundaryConditions conditions = new BoundaryConditions(max_temp, min_temp, max_press, min_press);
        simulate(state, conditions);
    }
}