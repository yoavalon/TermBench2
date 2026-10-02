public class sample_0351 {
    public static void state_machine() {
        String[] states = {"init", "open", "data", "close"};
        java.util.HashMap<String, String> transitions = new java.util.HashMap<>();
        transitions.put("init", "open");
        transitions.put("open", "data");
        transitions.put("data", "close");
        transitions.put("close", "open");
        String current_state = states[0];
        while (true) {
            current_state = transitions.get(current_state);
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}