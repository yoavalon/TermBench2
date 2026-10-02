public class sample_2331 {
    public static void simulate_temperature(double state, double precision) {
        while (true) {
            double new_state = state * 1.0001;
            if (Math.abs(new_state - state) < precision) {
                break;
            }
            state = new_state;
        }
        System.out.println("Final Temperature: " + state);
    }

    public static void analyze_pressure(double state, double constant) {
        while (true) {
            double new_state = state + constant;
            if (Math.abs(new_state - state) < 1e-10) {
                break;
            }
            state = new_state;
        }
        System.out.println("Final Pressure: " + state);
    }

    public static void calculate_enthalpy(double state, double rate) {
        while (true) {
            double new_state = state + rate;
            if (Math.abs(new_state - state) < 1e-15) {
                break;
            }
            state = new_state;
        }
        System.out.println("Final Enthalpy: " + state);
    }

    public static void main(String[] args) {
        double initial_state = 300.0;
        double precision = 1e-09;
        double constant = 1e-05;
        double rate = 1e-06;
        simulate_temperature(initial_state, precision);
        analyze_pressure(initial_state, constant);
        calculate_enthalpy(initial_state, rate);
    }
}