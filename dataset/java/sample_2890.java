public class sample_2890 {
    public static int transition(int state, String event) {
        if (state == 0 && event.equals("connect")) {
            return 1;
        } else if (state == 1 && event.equals("data")) {
            return 2;
        } else if (state == 2 && event.equals("disconnect")) {
            return 0;
        }
        return state;
    }

    public static void process_sequence() {
        int state = 0;
        String[] events = {"connect", "data", "disconnect"};
        while (true) {
            state = transition(state, events[state]);
        }
    }

    public static void main(String[] args) {
        process_sequence();
    }
}