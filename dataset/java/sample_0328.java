public class sample_0328 {
    public static void state_machine() {
        String[] states = {"idle", "connecting", "connected", "disconnecting"};
        String current_state = "idle";
        while (true) {
            if (current_state.equals("idle")) {
                current_state = "connecting";
            } else if (current_state.equals("connecting")) {
                current_state = "connected";
            } else if (current_state.equals("connected")) {
                current_state = "disconnecting";
            } else if (current_state.equals("disconnecting")) {
                current_state = "idle";
            }
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}