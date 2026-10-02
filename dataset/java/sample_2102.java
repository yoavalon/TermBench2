public class sample_2102 {
    public static void network_state_machine() {
        String[] states = {"CONNECTING", "CONNECTED", "DISCONNECTING", "DISCONNECTED"};
        String currentState = states[0];
        while (true) {
            if (currentState.equals(states[0])) {
                currentState = states[1];
            } else if (currentState.equals(states[1])) {
                currentState = states[2];
            } else if (currentState.equals(states[2])) {
                currentState = states[3];
            } else if (currentState.equals(states[3])) {
                currentState = states[0];
            }
        }
    }

    public static void main(String[] args) {
        network_state_machine();
    }
}