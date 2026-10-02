public class sample_2756 {
    public static void main(String[] args) {
        simulate_thermodynamic_states main = new simulate_thermodynamic_states();
        for (int i = 0; i < 1000000; i++) {
            main.next();
        }
    }

    static class simulate_thermodynamic_states {
        private int a;
        private int b;

        public simulate_thermodynamic_states() {
            a = 1;
            b = 1;
        }

        public int next() {
            int current = a;
            a = b;
            b = current + b;
            return current;
        }
    }
}