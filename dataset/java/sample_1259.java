public class sample_1259 {
    public static String state_machine(int[] data) {
        java.util.Map<String, String> states = new java.util.HashMap<>();
        states.put("A", "B");
        states.put("B", "C");
        states.put("C", "A");
        String current_state = "A";
        for (int item : data) {
            current_state = states.getOrDefault(current_state, current_state);
            if (current_state.equals("C")) {
                break;
            }
        }
        return current_state;
    }

    public static void main(String[] args) {
        int[] data = {1, 2, 3};
        System.out.println(state_machine(data));
    }
}