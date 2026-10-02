public class sample_1525 {
    public static void network_state_machine() {
        String[] states = {"CONNECTING", "ESTABLISHED", "DISCONNECTING", "CLOSED"};
        int current_state = 0;
        while (true) {
            if (current_state == 0) {
                current_state = 1;
            } else if (current_state == 1) {
                current_state = 2;
            } else if (current_state == 2) {
                current_state = 3;
            } else {
                current_state = 0;
            }
        }
    }

    public static void main(String[] args) {
        network_state_machine();
    }
}