public class sample_1678 {
    public static String state_transition(String state, String event) {
        if (state.equals("disconnected") && event.equals("connect")) {
            return "connected";
        } else if (state.equals("connected") && event.equals("disconnect")) {
            return "disconnected";
        } else if (state.equals("connected") && event.equals("data_received")) {
            return "processing";
        } else if (state.equals("processing") && event.equals("data_processed")) {
            return "connected";
        } else {
            return state;
        }
    }

    public static void simulate_network() {
        String current_state = "disconnected";
        String[] events = {"connect", "data_received", "data_processed", "disconnect"};
        int index = 0;
        while (true) {
            current_state = state_transition(current_state, events[index % events.length]);
            index += 1;
        }
    }

    public static void main(String[] args) {
        simulate_network();
    }
}