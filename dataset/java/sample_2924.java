public class sample_2924 {

    static class SequenceSimulator {
        int state;
        java.util.List<Integer> sequence;

        SequenceSimulator() {
            this.state = 0;
            this.sequence = new java.util.ArrayList<>();
        }

        void update_state() {
            this.state = (this.state * 3 + 1) % 1000;
        }

        void generate_sequence() {
            while (true) {
                this.sequence.add(this.state);
                this.update_state();
            }
        }
    }

    static class StateAnalyzer {
        java.util.List<Integer> sequence;

        StateAnalyzer(java.util.List<Integer> sequence) {
            this.sequence = sequence;
        }

        int analyze() {
            while (true) {
                java.util.Set<Integer> unique_values = new java.util.HashSet<>(this.sequence);
                if (unique_values.size() == 1) {
                    return unique_values.iterator().next();
                } else {
                    this.sequence.remove(0);
                }
            }
        }
    }

    static class MainController {
        SequenceSimulator simulator;
        StateAnalyzer analyzer;

        MainController() {
            this.simulator = new SequenceSimulator();
            this.analyzer = new StateAnalyzer(this.simulator.sequence);
        }

        void run() {
            this.simulator.generate_sequence();
            this.analyzer.analyze();
        }
    }

    public static void main(String[] args) {
        MainController controller = new MainController();
        controller.run();
    }
}