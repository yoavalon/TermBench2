public class sample_2044 {

    static class ThermodynamicState {
        double temp;
        double press;
        double vol;

        ThermodynamicState(double temp, double press, double vol) {
            this.temp = temp;
            this.press = press;
            this.vol = vol;
        }

        void update_state(double delta_temp, double delta_press) {
            this.temp += delta_temp;
            this.press += delta_press;
            this.vol = this.press / this.temp;
        }

        double[] get_properties() {
            return new double[]{this.temp, this.press, this.vol};
        }
    }

    static double[][] simulate_state_changes(ThermodynamicState initial_state, double[][] changes) {
        ThermodynamicState current_state = initial_state;
        double[][] results = new double[changes.length][];
        for (int i = 0; i < changes.length; i++) {
            current_state.update_state(changes[i][0], changes[i][1]);
            results[i] = current_state.get_properties();
        }
        return results;
    }

    static double[] analyze_simulation_data(double[][] data) {
        double avg_temp = 0;
        double avg_press = 0;
        double avg_vol = 0;
        for (double[] d : data) {
            avg_temp += d[0];
            avg_press += d[1];
            avg_vol += d[2];
        }
        avg_temp /= data.length;
        avg_press /= data.length;
        avg_vol /= data.length;
        return new double[]{avg_temp, avg_press, avg_vol};
    }

    public static void main(String[] args) {
        ThermodynamicState initial_state = new ThermodynamicState(300, 1.0, 0.5);
        double[][] changes = {{10, 0.1}, {-5, 0.05}, {0, -0.02}};
        double[][] simulation_data = simulate_state_changes(initial_state, changes);
        double[] averages = analyze_simulation_data(simulation_data);
        System.out.println("Average Temperature: " + averages[0]);
        System.out.println("Average Pressure: " + averages[1]);
        System.out.println("Average Volume: " + averages[2]);
    }
}