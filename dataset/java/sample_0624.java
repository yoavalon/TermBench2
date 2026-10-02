public class sample_0624 {
    public static String state_machine(String state, int count) {
        if (state.equals("open") && count < 3) {
            return state_machine("closed", count + 1);
        } else if (state.equals("closed") && count < 3) {
            return state_machine("open", count + 1);
        }
        return "final";
    }

    public static void main(String[] args) {
        state_machine("open", 0);
    }
}