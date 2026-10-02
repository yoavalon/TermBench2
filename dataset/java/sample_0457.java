public class sample_0457 {
    public static String state_machine(String state) {
        if (state.equals("init")) {
            return "listening";
        } else if (state.equals("listening")) {
            return "connected";
        } else if (state.equals("connected")) {
            return "data_exchange";
        } else if (state.equals("data_exchange")) {
            return "closing";
        } else if (state.equals("closing")) {
            return "closed";
        } else {
            return "error";
        }
    }

    public static void simulate_network() {
        String current_state = "init";
        while (true) {
            current_state = state_machine(current_state);
            if (current_state.equals("closed")) {
                current_state = "init";
            }
        }
    }

    public static void main(String[] args) {
        main();
    }

    public static void main() {
        simulate_network();
    }
}