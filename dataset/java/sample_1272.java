public class sample_1272 {
    public static void main(String[] args) {
        network_state_machine();
    }

    public static void network_state_machine() {
        String[] states = {"idle", "connected", "failed"};
        java.util.Map<String, String> transitions = new java.util.HashMap<>();
        transitions.put("idle", "connected");
        transitions.put("connected", "failed");
        transitions.put("failed", "idle");
        String state = "idle";
        for (int _ = 0; _ < 3; _++) {
            state = transitions.get(state);
        }
    }
}