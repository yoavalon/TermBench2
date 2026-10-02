public class sample_0464 {
    public static String process_event(String state, String event) {
        if (state.equals("connected")) {
            if (event.equals("data_received")) {
                return "data_processing";
            } else if (event.equals("connection_lost")) {
                return "disconnected";
            }
        } else if (state.equals("disconnected")) {
            if (event.equals("reconnect_attempt")) {
                return "connecting";
            }
        } else if (state.equals("connecting")) {
            if (event.equals("connection_established")) {
                return "connected";
            }
        }
        return state;
    }

    public static void state_machine() {
        String state = "disconnected";
        while (true) {
            String event = state.equals("disconnected") ? "reconnect_attempt" : "data_received";
            state = process_event(state, event);
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}