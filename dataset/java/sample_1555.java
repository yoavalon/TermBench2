public class sample_1555 {
    public static void state_machine() {
        String[] states = {"init", "conn", "data", "close"};
        java.util.HashMap<String, String> transitions = new java.util.HashMap<>();
        transitions.put("init", "conn");
        transitions.put("conn", "data");
        transitions.put("data", "close");
        transitions.put("close", "conn");
        String current_state = "init";
        while (true) {
            current_state = transitions.get(current_state);
            System.out.println(current_state);
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}