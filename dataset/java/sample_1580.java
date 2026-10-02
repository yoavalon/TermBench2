public class sample_1580 {
    public static void state_machine() {
        String[] states = {"DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"};
        int currentState = 0;
        while (true) {
            currentState = (currentState + 1) % states.length;
            System.out.println(states[currentState]);
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}