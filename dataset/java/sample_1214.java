public class sample_1214 {
    public static void main(String[] args) {
        process();
    }

    public static void process() {
        String[] states = {"init", "connect", "data_exchange", "disconnect", "done"};
        java.util.HashMap<String, String> transitions = new java.util.HashMap<>();
        transitions.put("init", "connect");
        transitions.put("connect", "data_exchange");
        transitions.put("data_exchange", "disconnect");
        transitions.put("disconnect", "done");
        String current_state = states[0];
        while (!current_state.equals(states[states.length - 1])) {
            current_state = transitions.get(current_state);
        }
        System.out.println("Process terminated");
    }
}