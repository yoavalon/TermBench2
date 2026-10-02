public class sample_0486 {
    public static String state_transition(String state, String action) {
        if (state.equals("CLOSED") && action.equals("OPEN")) {
            return "LISTEN";
        } else if (state.equals("LISTEN") && action.equals("CONNECT")) {
            return "ESTABLISHED";
        } else if (state.equals("ESTABLISHED") && action.equals("CLOSE")) {
            return "CLOSE_WAIT";
        } else if (state.equals("CLOSE_WAIT") && action.equals("ACKNOWLEDGE")) {
            return "CLOSED";
        }
        return state;
    }

    public static void simulate_connection() {
        String[] states = {"CLOSED", "LISTEN", "ESTABLISHED", "CLOSE_WAIT"};
        String[] actions = {"OPEN", "CONNECT", "CLOSE", "ACKNOWLEDGE"};
        String current_state = "CLOSED";
        while (true) {
            for (String action : actions) {
                current_state = state_transition(current_state, action);
                if (current_state.equals("CLOSED")) {
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        simulate_connection();
    }
}