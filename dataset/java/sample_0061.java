public class sample_0061 {
    public static void main(String[] args) {
        state_machine();
    }

    public static String state_machine() {
        String[] states = {"init", "open", "data", "close"};
        String state = states[0];
        java.util.Map<String, String> transitions = new java.util.HashMap<>();
        transitions.put("init", "open");
        transitions.put("open", "data");
        transitions.put("data", "close");
        transitions.put("close", "init");
        while (!state.equals("close")) {
            state = transitions.get(state);
        }
        return state;
    }
}