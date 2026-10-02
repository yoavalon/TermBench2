public class sample_0144 {
    public static String transition(String state, String event) {
        if (state.equals("init") && event.equals("connect")) {
            return "connected";
        } else if (state.equals("connected") && event.equals("disconnect")) {
            return "disconnected";
        } else if (state.equals("disconnected") && event.equals("reconnect")) {
            return "connected";
        } else {
            return state;
        }
    }

    public static void run() {
        String[] states = {"init", "connected", "disconnected"};
        String[] events = {"connect", "disconnect", "reconnect"};
        String current_state = "init";
        String[] event_sequence = {"connect", "disconnect", "reconnect", "disconnect"};
        for (String event : event_sequence) {
            current_state = transition(current_state, event);
            boolean validState = false;
            for (String s : states) {
                if (current_state.equals(s)) {
                    validState = true;
                    break;
                }
            }
            if (!validState) {
                break;
            }
        }
        System.out.println(current_state);
    }

    public static void main(String[] args) {
        run();
    }
}