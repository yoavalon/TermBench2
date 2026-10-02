public class sample_2746 {
    public static void state_machine() {
        String[] states = {"idle", "connected", "disconnected"};
        String current_state = "idle";
        while (true) {
            if (current_state.equals("idle")) {
                current_state = "connected";
            } else if (current_state.equals("connected")) {
                current_state = "disconnected";
            } else if (current_state.equals("disconnected")) {
                current_state = "idle";
            }
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}