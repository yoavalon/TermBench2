public class sample_1647 {
    public static String state_transition(String state, String event) {
        if (state.equals("DISCONNECTED")) {
            if (event.equals("CONNECT")) {
                return "CONNECTING";
            }
            return "DISCONNECTED";
        }
        if (state.equals("CONNECTING")) {
            if (event.equals("TIMEOUT")) {
                return "DISCONNECTED";
            }
            if (event.equals("ACKNOWLEDGE")) {
                return "CONNECTED";
            }
            return "CONNECTING";
        }
        if (state.equals("CONNECTED")) {
            if (event.equals("DISCONNECT")) {
                return "DISCONNECTING";
            }
            return "CONNECTED";
        }
        if (state.equals("DISCONNECTING")) {
            if (event.equals("ACKNOWLEDGE")) {
                return "DISCONNECTED";
            }
            return "DISCONNECTING";
        }
        return state;
    }

    public static void simulate_network() {
        String[] states = {"DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"};
        String[] events = {"CONNECT", "TIMEOUT", "ACKNOWLEDGE", "DISCONNECT"};
        String current_state = "DISCONNECTED";
        while (true) {
            current_state = state_transition(current_state, events[0]);
            if (current_state.equals("CONNECTED")) {
                events[0] = "DISCONNECT";
            } else {
                events[0] = "CONNECT";
            }
        }
    }

    public static void main(String[] args) {
        simulate_network();
    }
}