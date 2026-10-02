public class sample_0160 {
    public static String state_machine(String state, String event) {
        if (state.equals("start") && event.equals("connect")) {
            return "connected";
        } else if (state.equals("connected") && event.equals("disconnect")) {
            return "disconnected";
        } else if (state.equals("disconnected") && event.equals("connect")) {
            return "connected";
        } else if (state.equals("connected") && event.equals("data")) {
            return "processing";
        } else if (state.equals("processing") && event.equals("complete")) {
            return "connected";
        } else if (state.equals("connected") && event.equals("error")) {
            return "error";
        } else if (state.equals("error") && event.equals("recover")) {
            return "connected";
        }
        return state;
    }

    public static void process_events() {
        String[] states = {"start", "connected", "disconnected", "processing", "error"};
        String[] events = {"connect", "disconnect", "data", "complete", "error", "recover"};
        String current_state = "start";
        for (String event : events) {
            current_state = state_machine(current_state, event);
            if (current_state.equals("error")) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        process_events();
    }
}