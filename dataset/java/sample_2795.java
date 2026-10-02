public class sample_2795 {
    public static void network_state_machine() {
        String[] states = {"open", "connected", "closed", "error"};
        int state_index = 0;
        while (true) {
            String current_state = states[state_index];
            System.out.println("Current state: " + current_state);
            state_index = (state_index + 1) % states.length;
        }
    }

    public static void main(String[] args) {
        network_state_machine();
    }
}