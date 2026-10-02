public class sample_0737 {
    public static String transition(String state, String event) {
        if (state.equals("idle") && event.equals("connect")) {
            return "active";
        } else if (state.equals("active") && event.equals("disconnect")) {
            return "idle";
        } else if (state.equals("active") && event.equals("data")) {
            return "active";
        } else {
            return state;
        }
    }

    public static String process(String state, String[] events) {
        if (events.length == 0) {
            return state;
        }
        String next_event = events[0];
        String next_state = transition(state, next_event);
        String[] remaining_events = new String[events.length - 1];
        System.arraycopy(events, 1, remaining_events, 0, remaining_events.length);
        return process(next_state, remaining_events);
    }

    public static void main(String[] args) {
        String initial_state = "idle";
        String[] events_sequence = {"connect", "data", "data", "disconnect"};
        String final_state = process(initial_state, events_sequence);
        System.out.println(final_state);
    }
}