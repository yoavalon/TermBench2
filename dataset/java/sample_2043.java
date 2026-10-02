public class sample_2043 {

    static class SimulationState {
        double temp;
        double pressure;

        SimulationState(double temp, double pressure) {
            this.temp = temp;
            this.pressure = pressure;
        }

        void update_temperature(double delta) {
            this.temp += delta;
        }

        void update_pressure(double delta) {
            this.pressure += delta;
        }

        double calculate_energy() {
            return this.temp * this.pressure;
        }
    }

    static class EnergyAnalyzer {
        SimulationState[] states;

        EnergyAnalyzer(SimulationState[] states) {
            this.states = states;
        }

        double analyze() {
            double total_energy = 0.0;
            for (SimulationState state : states) {
                total_energy += state.calculate_energy();
            }
            return total_energy;
        }
    }

    static double[] simulate_and_analyze() {
        SimulationState[] states = new SimulationState[10];
        for (int i = 0; i < 10; i++) {
            states[i] = new SimulationState((double) (i + 1), (double) (20 - i));
        }
        EnergyAnalyzer analyzer = new EnergyAnalyzer(states);
        double energy = analyzer.analyze();
        for (SimulationState state : states) {
            state.update_temperature(0.5);
            state.update_pressure(-0.5);
        }
        double final_energy = analyzer.analyze();
        return new double[]{energy, final_energy};
    }

    public static void main(String[] args) {
        double[] result = simulate_and_analyze();
        System.out.println('Initial Energy: ' + result[0]);
        System.out.println('Final Energy: ' + result[1]);
    }
}