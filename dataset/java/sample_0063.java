public class sample_0063 {
    public static void main(String[] args) {
        state_machine();
    }

    public static String state_machine() {
        String[] states = {"DISCONNECTED", "CONNECTING", "CONNECTED", "TERMINATING"};
        String current_state = states[0];
        for (int _ = 0; _ < states.length - 1; _++) {
            if (current_state.equals("CONNECTED")) {
                current_state = states[states.length - 1];
                break;
            }
            current_state = states[states.length - 1];
        }
        return current_state;
    }
}