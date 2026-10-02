import java.util.ArrayList;
import java.util.List;

public class sample_2038 {

    static class ThermodynamicState {
        double temp;
        double pressure;

        ThermodynamicState(double temp, double pressure) {
            this.temp = temp;
            this.pressure = pressure;
        }

        void update_state(double temp_change, double pressure_change) {
            this.temp += temp_change;
            this.pressure += pressure_change;
        }

        double calculate_entropy() {
            if (this.temp <= 0) {
                return Double.NaN;
            }
            return this.pressure / this.temp;
        }
    }

    static class SimulationController {
        ThermodynamicState state;
        int iterations;
        List<Double> data;

        SimulationController(ThermodynamicState initial_state, int iterations) {
            this.state = initial_state;
            this.iterations = iterations;
            this.data = new ArrayList<>();
        }

        void run_simulation() {
            for (int i = 0; i < this.iterations; i++) {
                this.state.update_state(0.1, -0.05);
                this.data.add(this.state.calculate_entropy());
            }
        }

        List<Double> get_results() {
            return this.data;
        }
    }

    static double analyze_data(List<Double> data) {
        double total = 0;
        int count = 0;
        for (double value : data) {
            if (!Double.isNaN(value)) {
                total += value;
                count++;
            }
        }
        return count > 0 ? total / count : Double.NaN;
    }

    public static void main(String[] args) {
        ThermodynamicState initial_state = new ThermodynamicState(300, 100);
        SimulationController controller = new SimulationController(initial_state, 50);
        controller.run_simulation();
        List<Double> results = controller.get_results();
        double average_entropy = analyze_data(results);
        System.out.println("Average Entropy: " + average_entropy);
    }
}