public class sample_1233 {
    public static void main(String[] args) {
        String[] states = {"start", "open", "data", "close", "end"};
        java.util.Map<String, String> transitions = new java.util.HashMap<>();
        transitions.put("start", "open");
        transitions.put("open", "data");
        transitions.put("data", "close");
        transitions.put("close", "end");
        String current_state = "start";
        while (!current_state.equals("end")) {
            current_state = transitions.get(current_state);
        }
        System.out.println(current_state);
    }
}