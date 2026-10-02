public class sample_0622 {
    public static String state_machine(String state, int count, int max_count) {
        if (count >= max_count) {
            return "Terminated";
        }
        if (state.equals("CONNECTING")) {
            return state_machine("OPEN", count + 1, max_count);
        }
        if (state.equals("OPEN")) {
            return state_machine("CLOSING", count + 1, max_count);
        }
        if (state.equals("CLOSING")) {
            return state_machine("DISCONNECTED", count + 1, max_count);
        }
        if (state.equals("DISCONNECTED")) {
            return state_machine("RECONNECTING", count + 1, max_count);
        }
        if (state.equals("RECONNECTING")) {
            return state_machine("CONNECTING", count + 1, max_count);
        }
        return state;
    }

    public static void main(String[] args) {
        state_machine("CONNECTING", 0, 10);
    }
}