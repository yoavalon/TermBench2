public class sample_0687 {
    public static String state_machine(String state, int steps) {
        if (steps == 0) {
            return state;
        }
        if (state.equals("open")) {
            return state_machine("close", steps - 1);
        }
        if (state.equals("close")) {
            return state_machine("open", steps - 1);
        }
        return state;
    }

    public static void main(String[] args) {
        System.out.println(state_machine("open", 5));
    }
}