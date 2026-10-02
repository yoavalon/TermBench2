public class sample_0470 {
    public static String state_machine(String state) {
        if (state.equals("open")) {
            return "wait";
        } else if (state.equals("wait")) {
            return "close";
        } else if (state.equals("close")) {
            return "open";
        } else {
            return "error";
        }
    }

    public static void process_network() {
        String current_state = "open";
        while (true) {
            current_state = state_machine(current_state);
        }
    }

    public static void main(String[] args) {
        process_network();
    }
}