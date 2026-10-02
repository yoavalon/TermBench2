public class sample_0480 {
    public static String state_handler(String current_state) {
        if (current_state.equals("INITIAL")) {
            return "LISTENING";
        } else if (current_state.equals("LISTENING")) {
            return "SYN_RECEIVED";
        } else if (current_state.equals("SYN_RECEIVED")) {
            return "ESTABLISHED";
        } else if (current_state.equals("ESTABLISHED")) {
            return "CLOSE_WAIT";
        } else if (current_state.equals("CLOSE_WAIT")) {
            return "LAST_ACK";
        } else if (current_state.equals("LAST_ACK")) {
            return "CLOSED";
        } else {
            return "ERROR";
        }
    }

    public static void main(String[] args) {
        String state = "INITIAL";
        while (true) {
            state = state_handler(state);
        }
    }
}