public class sample_0438 {
    public static String state_change(String state) {
        if (state.equals("idle")) {
            return "listening";
        } else if (state.equals("listening")) {
            return "connected";
        } else if (state.equals("connected")) {
            return "closing";
        } else if (state.equals("closing")) {
            return "idle";
        } else {
            return "error";
        }
    }

    public static void network_protocol() {
        String current_state = "idle";
        while (true) {
            current_state = state_change(current_state);
            System.out.println(current_state);
        }
    }

    public static void main(String[] args) {
        network_protocol();
    }
}