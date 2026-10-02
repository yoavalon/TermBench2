public class sample_0266 {
    static class Simulation {
        double state;

        Simulation(double state) {
            this.state = state;
        }

        void update_state(double change) {
            this.state += change;
        }

        boolean is_stable() {
            return Math.abs(this.state) < 0.01;
        }
    }

    static class BoundaryConditions {
        double min_val;
        double max_val;

        BoundaryConditions(double min_val, double max_val) {
            this.min_val = min_val;
            this.max_val = max_val;
        }

        double enforce_boundaries(double state) {
            if (state < this.min_val) {
                return this.min_val;
            } else if (state > this.max_val) {
                return this.max_val;
            }
            return state;
        }
    }

    static class Controller {
        Simulation simulation;
        BoundaryConditions boundary_conditions;

        Controller(Simulation simulation, BoundaryConditions boundary_conditions) {
            this.simulation = simulation;
            this.boundary_conditions = boundary_conditions;
        }

        void run() {
            double change = 0.1;
            while (true) {
                this.simulation.update_state(change);
                this.simulation.state = this.boundary_conditions.enforce_boundaries(this.simulation.state);
                if (this.simulation.is_stable()) {
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        Simulation simulation = new Simulation(0.0);
        BoundaryConditions boundary_conditions = new BoundaryConditions(-1.0, 1.0);
        Controller controller = new Controller(simulation, boundary_conditions);
        controller.run();
    }
}