public class sample_2724 {
    public static void simulate_thermodynamic_states() {
        int state = 0;
        while (true) {
            state += 1;
            int energy = state * state;
            int pressure = energy + state;
            System.out.println("State: " + state + ", Energy: " + energy + ", Pressure: " + pressure);
        }
    }

    public static void main(String[] args) {
        simulate_thermodynamic_states();
    }
}