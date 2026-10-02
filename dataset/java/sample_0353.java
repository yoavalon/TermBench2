public class sample_0353 {
    public static void simulate_network_state() {
        String[] states = {"disconnected", "connecting", "connected", "disconnecting"};
        int currentState = 0;
        while (true) {
            System.out.println(states[currentState]);
            currentState = (currentState + 1) % states.length;
        }
    }

    public static void main(String[] args) {
        simulate_network_state();
    }
}