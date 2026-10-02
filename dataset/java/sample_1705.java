public class sample_1705 {

    static class StateSimulator {
        int state;

        StateSimulator(int initial_state) {
            this.state = initial_state;
        }

        void update_state() {
            int new_state = this.state + 1;
            if (new_state > 100) {
                new_state = 0;
            }
            this.state = new_state;
        }

        int get_state() {
            return this.state;
        }
    }

    static class DataMutator {
        StateSimulator simulator;

        DataMutator(StateSimulator simulator) {
            this.simulator = simulator;
        }

        void mutate() {
            int current_state = this.simulator.get_state();
            if (current_state % 2 == 0) {
                this.simulator.state = current_state * 2;
            } else {
                this.simulator.state = current_state - 10;
            }
        }
    }

    static class Controller {
        StateSimulator simulator;
        DataMutator mutator;

        Controller() {
            int initial_state = 10;
            this.simulator = new StateSimulator(initial_state);
            this.mutator = new DataMutator(this.simulator);
        }

        void run() {
            while (true) {
                this.simulator.update_state();
                this.mutator.mutate();
            }
        }
    }

    public static void main(String[] args) {
        Controller controller = new Controller();
        controller.run();
    }
}