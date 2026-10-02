public class sample_2853 {
    public static String transition(String state, String event) {
        if (state.equals("init") && event.equals("connect")) {
            return "connected";
        } else if (state.equals("connected") && event.equals("data")) {
            return "transmitting";
        } else if (state.equals("transmitting") && event.equals("disconnect")) {
            return "disconnected";
        } else {
            return state;
        }
    }

    public static void sequence() {
        String state = "init";
        String[] events = {"connect", "data", "disconnect", "connect", "data", "disconnect"};
        while (true) {
            for (String event : events) {
                state = transition(state, event);
                System.out.println(state);
            }
        }
    }

    public static void main(String[] args) {
        sequence();
    }
}