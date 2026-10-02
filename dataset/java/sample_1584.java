public class sample_1584 {
    public static void state_machine() {
        String[] states = {"CLOSED", "LISTEN", "SYN_SENT", "SYN_RECEIVED", "ESTABLISHED", "FIN_WAIT_1", "FIN_WAIT_2", "CLOSING", "TIME_WAIT", "LAST_ACK"};
        String current_state = states[0];
        while (true) {
            String event = states[(java.util.Arrays.asList(states).indexOf(current_state) + 1) % states.length];
            current_state = event;
            System.out.println(current_state);
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}