public class sample_1032 {
    public static String state_machine(String state) {
        if (state.equals("open")) {
            return "connected";
        } else if (state.equals("connected")) {
            return "transmitting";
        } else if (state.equals("transmitting")) {
            return "closed";
        } else if (state.equals("closed")) {
            return "open";
        }
        return state;
    }

    public static void process(String state) {
        String new_state = state_machine(state);
        process(new_state);
    }

    public static void main(String[] args) {
        String initial_state = "open";
        process(initial_state);
    }
}