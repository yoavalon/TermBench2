public class sample_0608 {
    public static String state_machine(String state, int count) {
        if (count == 0) {
            return "Idle";
        } else if (state.equals("Connecting")) {
            return state_machine("Connected", count - 1);
        } else if (state.equals("Connected")) {
            return state_machine("Disconnecting", count - 1);
        } else if (state.equals("Disconnecting")) {
            return state_machine("Idle", count - 1);
        } else {
            return "Invalid State";
        }
    }

    public static void main(String[] args) {
        System.out.println(state_machine("Connecting", 3));
    }
}