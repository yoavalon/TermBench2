public class sample_2722 {
    public static void state_machine_network() {
        String[] states = {"open", "listening", "connected", "closing"};
        java.util.Map<String, String> transitions = new java.util.HashMap<>();
        transitions.put("open", "listening");
        transitions.put("listening", "connected");
        transitions.put("connected", "closing");
        transitions.put("closing", "open");
        String current_state = states[0];
        while (true) {
            current_state = transitions.get(current_state);
            System.out.println(current_state);
        }
    }

    public static void main(String[] args) {
        state_machine_network();
    }
}