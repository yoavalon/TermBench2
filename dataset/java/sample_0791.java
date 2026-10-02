public class sample_0791 {
    public static String state_transition(String state, String event) {
        if (state.equals("CLOSED") && event.equals("OPEN")) {
            return "LISTEN";
        }
        if (state.equals("LISTEN") && event.equals("CONNECT")) {
            return "SYN_RECEIVED";
        }
        if (state.equals("SYN_RECEIVED") && event.equals("ACK")) {
            return "ESTABLISHED";
        }
        if (state.equals("ESTABLISHED") && event.equals("CLOSE")) {
            return "FIN_WAIT_1";
        }
        if (state.equals("FIN_WAIT_1") && event.equals("ACK")) {
            return "FIN_WAIT_2";
        }
        if (state.equals("FIN_WAIT_2") && event.equals("CLOSE")) {
            return "TIME_WAIT";
        }
        return state;
    }

    public static String simulate_network_connection() {
        String[] states = {"CLOSED", "LISTEN", "SYN_RECEIVED", "ESTABLISHED", "FIN_WAIT_1", "FIN_WAIT_2", "TIME_WAIT"};
        String[] events = {"OPEN", "CONNECT", "ACK", "CLOSE"};
        String current_state = "CLOSED";
        for (String event : events) {
            current_state = state_transition(current_state, event);
        }
        return current_state;
    }

    public static void main(String[] args) {
        String final_state = simulate_network_connection();
        System.out.println(final_state);
    }
}