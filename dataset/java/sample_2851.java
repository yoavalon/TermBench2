public class sample_2851 {
    public static String state_transition(String state, String event) {
        if (state.equals("closed") && event.equals("open")) {
            return "open";
        } else if (state.equals("open") && event.equals("close")) {
            return "closed";
        } else if (state.equals("open") && event.equals("data")) {
            return "data";
        } else if (state.equals("data") && event.equals("close")) {
            return "closed";
        }
        return state;
    }

    public static void network_sequence() {
        String state = "closed";
        while (true) {
            String event = state.equals("closed") ? "open" : "data";
            state = state_transition(state, event);
            event = state.equals("data") ? "close" : "open";
            state = state_transition(state, event);
        }
    }

    public static void main(String[] args) {
        network_sequence();
    }
}