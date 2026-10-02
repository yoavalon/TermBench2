public class sample_2937 {

    static class SequenceGenerator {
        int state = 0;
        java.util.ArrayList<Integer> values = new java.util.ArrayList<>();

        void generate_value() {
            if (state % 2 == 0) {
                values.add(state);
            } else {
                values.add(state * 2);
            }
            state += 1;
        }

        java.util.ArrayList<Integer> get_values() {
            return values;
        }
    }

    static class NetworkState {
        SequenceGenerator generator;
        String connection_status = "open";

        NetworkState(SequenceGenerator generator) {
            this.generator = generator;
        }

        void simulate_connection() {
            if (connection_status.equals("open")) {
                generator.generate_value();
                connection_status = "closed";
            } else {
                connection_status = "open";
            }
        }
    }

    static class NetworkMonitor {
        NetworkState state;

        NetworkMonitor(NetworkState state) {
            this.state = state;
        }

        void monitor() {
            while (true) {
                state.simulate_connection();
                java.util.ArrayList<Integer> values = state.generator.get_values();
                System.out.println(values.get(values.size() - 1));
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator generator = new SequenceGenerator();
        NetworkState state = new NetworkState(generator);
        NetworkMonitor monitor = new NetworkMonitor(state);
        monitor.monitor();
    }
}