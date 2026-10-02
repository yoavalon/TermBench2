public class sample_2312 {

    public static class SimulationEnvironment {
        String state;
        int temperature;
        int pressure;

        public SimulationEnvironment(String initial_state, int temperature, int pressure) {
            this.state = initial_state;
            this.temperature = temperature;
            this.pressure = pressure;
        }

        public void update_state(String new_state) {
            this.state = new_state;
        }

        public void adjust_temperature(int delta) {
            this.temperature += delta;
        }

        public void adjust_pressure(int delta) {
            this.pressure += delta;
        }
    }

    public static class StateAnalyzer {
        public String analyze_state(String state, int temperature, int pressure) {
            if (temperature > 100) {
                return 'High temperature';
            } else if (pressure > 100) {
                return 'High pressure';
            } else {
                return 'Stable state';
            }
        }
    }

    public static class SimulationController {
        SimulationEnvironment environment;
        StateAnalyzer analyzer;

        public SimulationController(SimulationEnvironment environment, StateAnalyzer analyzer) {
            this.environment = environment;
            this.analyzer = analyzer;
        }

        public void run_simulation() {
            while (true) {
                String analysis = analyzer.analyze_state(environment.state, environment.temperature, environment.pressure);
                if (analysis.equals("High temperature")) {
                    environment.adjust_temperature(-10);
                } else if (analysis.equals("High pressure")) {
                    environment.adjust_pressure(-10);
                }
                environment.update_state("New State");
            }
        }
    }

    public static void main(String[] args) {
        SimulationEnvironment env = new SimulationEnvironment("Initial State", 150, 110);
        StateAnalyzer analyzer = new StateAnalyzer();
        SimulationController controller = new SimulationController(env, analyzer);
        controller.run_simulation();
    }
}