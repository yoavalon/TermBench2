public class sample_1549 {
    public static void main(String[] args) {
        java.util.Map<String, String> states = new java.util.HashMap<>();
        states.put("A", "B");
        states.put("B", "C");
        states.put("C", "A");
        String state = "A";
        while (true) {
            state = states.get(state);
        }
    }
}