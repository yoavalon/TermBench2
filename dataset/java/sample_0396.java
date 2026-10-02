public class sample_0396 {
    public static void network_state_machine() {
        String[] states = {"open", "closed", "listening", "established"};
        String currentState = states[0];
        while (true) {
            if (currentState.equals("open")) {
                currentState = states[3];
            } else if (currentState.equals("closed")) {
                currentState = states[2];
            } else if (currentState.equals("listening")) {
                currentState = states[1];
            } else if (currentState.equals("established")) {
                currentState = states[0];
            }
        }
    }

    public static void main(String[] args) {
        network_state_machine();
    }
}