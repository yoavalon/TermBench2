public class sample_2831 {
    public static int transition(int state, String event) {
        if (state == 0) {
            return "open".equals(event) ? 1 : state;
        } else if (state == 1) {
            return "data".equals(event) ? 2 : state;
        } else if (state == 2) {
            return "close".equals(event) ? 3 : state;
        } else {
            return 0;
        }
    }

    public static void simulate() {
        int state = 0;
        while (true) {
            state = transition(state, "open");
            state = transition(state, "data");
            state = transition(state, "close");
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}