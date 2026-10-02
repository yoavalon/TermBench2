public class sample_1294 {
    public static void main(String[] args) {
        String[] states = {"DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"};
        java.util.Map<String, String> transitions = new java.util.HashMap<>();
        transitions.put("DISCONNECTED", "CONNECTING");
        transitions.put("CONNECTING", "CONNECTED");
        transitions.put("CONNECTED", "DISCONNECTING");
        transitions.put("DISCONNECTING", "DISCONNECTED");
        String currentState = states[0];
        for (int i = 0; i < 4; i++) {
            currentState = transitions.get(currentState);
        }
        System.out.println(currentState);
    }
}