public class sample_0164 {
    public static String transition(String state, String event) {
        if (state.equals("idle") && event.equals("connect")) {
            return "connected";
        } else if (state.equals("connected") && event.equals("data")) {
            return "data_received";
        } else if (state.equals("data_received") && event.equals("disconnect")) {
            return "disconnected";
        } else {
            return state;
        }
    }

    public static String process_events(String[] events) {
        String current_state = "idle";
        for (String event : events) {
            current_state = transition(current_state, event);
            if (current_state.equals("disconnected")) {
                break;
            }
        }
        return current_state;
    }

    public static void main(String[] args) {
        String[] events = {"connect", "data", "disconnect", "connect"};
        String final_state = process_events(events);
        System.out.println(final_state);
    }
}