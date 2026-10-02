public class sample_0052 {
    public static void state_machine() {
        String state = "idle";
        java.util.Map<String, String> transitions = new java.util.HashMap<>();
        transitions.put("idle", "connecting");
        transitions.put("connecting", "connected");
        transitions.put("connected", "disconnected");
        transitions.put("disconnected", "idle");
        java.util.List<String> states = new java.util.ArrayList<>(transitions.values());
        for (int i = 0; i < states.size(); i++) {
            state = transitions.get(state);
            if (state.equals("idle")) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}