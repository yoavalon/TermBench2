public class sample_1317 {
    public static String transition(String state, String event) {
        if (state.equals("CLOSED") && event.equals("OPEN")) {
            return "OPEN";
        } else if (state.equals("OPEN") && event.equals("DATA")) {
            return "DATA";
        } else if (state.equals("DATA") && event.equals("CLOSE")) {
            return "CLOSED";
        } else if (state.equals("CLOSED") && event.equals("ERROR")) {
            return "ERROR";
        }
        return state;
    }

    public static String simulate() {
        String state = "CLOSED";
        String[] events = {"OPEN", "DATA", "CLOSE", "ERROR", "DATA", "CLOSE"};
        for (String event : events) {
            state = transition(state, event);
        }
        return state;
    }

    public static void main(String[] args) {
        simulate();
    }
}