public class sample_2788 {
    public static void network_state_machine() {
        String[] states = {"disconnected", "connecting", "connected", "disconnecting"};
        int state_index = 0;
        while (true) {
            String state = states[state_index];
            System.out.println(state);
            state_index = (state_index + 1) % states.length;
        }
    }

    public static void main(String[] args) {
        network_state_machine();
    }
}