public class sample_1371 {
    public static String process_connection(String state, String event) {
        if (state.equals("idle") && event.equals("connect")) {
            return "connected";
        } else if (state.equals("connected") && event.equals("data")) {
            return "data_received";
        } else if (state.equals("data_received") && event.equals("disconnect")) {
            return "disconnected";
        }
        return state;
    }

    public static void manage_state_machine() {
        String state = "idle";
        String[] events = {"connect", "data", "disconnect"};
        for (String event : events) {
            state = process_connection(state, event);
            if (state.equals("disconnected")) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        manage_state_machine();
    }
}