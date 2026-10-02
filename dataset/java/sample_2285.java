public class sample_2285 {
    public static String state_transition(String state, String input) {
        if (state.equals("idle") && input.equals("connect")) {
            return "connecting";
        } else if (state.equals("connecting") && input.equals("acknowledged")) {
            return "connected";
        } else if (state.equals("connected") && input.equals("disconnect")) {
            return "disconnecting";
        } else if (state.equals("disconnecting") && input.equals("disconnected")) {
            return "idle";
        }
        return state;
    }

    public static void process_inputs() {
        String current_state = "idle";
        String[] inputs = {"connect", "acknowledged", "disconnect", "disconnected"};
        while (true) {
            for (String input : inputs) {
                current_state = state_transition(current_state, input);
            }
        }
    }

    public static void main(String[] args) {
        process_inputs();
    }
}