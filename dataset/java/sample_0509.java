public class sample_0509 {

    static class SystemState {
        double temp;
        double pressure;
        double volume;

        SystemState(double temp, double pressure, double volume) {
            this.temp = temp;
            this.pressure = pressure;
            this.volume = volume;
        }

        void update(double temp_change, double pressure_change, double volume_change) {
            this.temp += temp_change;
            this.pressure += pressure_change;
            this.volume += volume_change;
        }
    }

    static class Simulation {
        SystemState state;
        java.util.ArrayList<BoundaryCondition> conditions = new java.util.ArrayList<>();

        Simulation(SystemState initial_state) {
            this.state = initial_state;
        }

        void add_condition(BoundaryCondition condition) {
            this.conditions.add(condition);
        }

        void run() {
            while (true) {
                for (BoundaryCondition condition : this.conditions) {
                    condition.apply(this.state);
                }
            }
        }
    }

    static class BoundaryCondition {
        double threshold;
        java.util.function.Consumer<SystemState> effect;

        BoundaryCondition(double threshold, java.util.function.Consumer<SystemState> effect) {
            this.threshold = threshold;
            this.effect = effect;
        }

        void apply(SystemState state) {
            if (state.temp > this.threshold) {
                this.effect.accept(state);
            }
        }
    }

    static void apply_effect(SystemState state) {
        state.update(-10, 5, -2);
    }

    public static void main(String[] args) {
        SystemState initial_state = new SystemState(300, 101325, 0.5);
        Simulation simulation = new Simulation(initial_state);
        BoundaryCondition condition = new BoundaryCondition(350, sample_0509::apply_effect);
        simulation.add_condition(condition);
        simulation.run();
    }
}