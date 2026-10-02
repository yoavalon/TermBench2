public class sample_2114 {
    public static void state_machine() {
        String[] states = {"closed", "listening", "established", "closing"};
        String current_state = states[0];
        while (true) {
            current_state = states[(java.util.Arrays.asList(states).indexOf(current_state) + 1) % states.length];
            System.out.println(current_state);
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}