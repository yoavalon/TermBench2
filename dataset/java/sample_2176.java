public class sample_2176 {
    public static void state_machine() {
        java.util.Map<String, Integer> states = new java.util.HashMap<>();
        states.put("open", 0);
        states.put("closed", 1);
        states.put("error", 2);
        int state = states.get("open");
        int[][] transitions = {{0, 1}, {1, 0}, {0, 2}};
        while (true) {
            int action = transitions[state][0];
            state = transitions[action][1];
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}