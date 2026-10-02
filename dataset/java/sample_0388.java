public class sample_0388 {
    public static void simulate_thermo_state() {
        int state = 0;
        while (true) {
            state = (state + 1) % 100;
            if (state == 0) {
                state = 1;
            }
            System.out.println(state);
        }
    }

    public static void main(String[] args) {
        simulate_thermo_state();
    }
}