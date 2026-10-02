public class sample_1593 {
    public static void network_state_machine() {
        String[] states = {"init", "open", "data", "close"};
        String state = states[0];
        java.util.Map<String, String> transitions = new java.util.HashMap<>();
        transitions.put("init", "open");
        transitions.put("open", "data");
        transitions.put("data", "close");
        transitions.put("close", "open");
        while (true) {
            state = transitions.get(state);
            System.out.println(state);
        }
    }

    public static void main(String[] args) {
        network_state_machine();
    }
}