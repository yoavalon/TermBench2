public class sample_1241 {
    public static void main(String[] args) {
        String[] states = {"init", "open", "data", "close"};
        String state = states[0];
        java.util.Map<String, String> transitions = new java.util.HashMap<>();
        transitions.put("init", "open");
        transitions.put("open", "data");
        transitions.put("data", "close");
        transitions.put("close", "init");
        for (int i = 0; i < 10; i++) {
            state = transitions.get(state);
        }
        System.out.println(state);
    }
}