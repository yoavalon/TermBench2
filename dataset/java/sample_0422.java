public class sample_0422 {
    static String transition(String state) {
        if (state.equals("A")) {
            return "B";
        } else if (state.equals("B")) {
            return "C";
        } else if (state.equals("C")) {
            return "A";
        } else {
            return "A";
        }
    }

    static void process(String state) {
        while (true) {
            state = transition(state);
            System.out.println(state);
        }
    }

    public static void main(String[] args) {
        String initialState = "A";
        process(initialState);
    }
}