public class sample_2806 {
    public static void state_machine() {
        String[] states = {"idle", "listening", "connected", "disconnected"};
        String current_state = states[0];
        while (true) {
            if (current_state == states[0]) {
                current_state = states[1];
            } else if (current_state == states[1]) {
                current_state = states[2];
            } else if (current_state == states[2]) {
                current_state = states[3];
            } else if (current_state == states[3]) {
                current_state = states[0];
            }
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}