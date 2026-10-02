public class sample_1643 {
    public static String transition(String state, String action) {
        if (state.equals("idle") && action.equals("connect")) {
            return "connected";
        } else if (state.equals("connected") && action.equals("send")) {
            return "data_sent";
        } else if (state.equals("data_sent") && action.equals("disconnect")) {
            return "disconnected";
        } else if (state.equals("disconnected") && action.equals("reconnect")) {
            return "reconnecting";
        } else if (state.equals("reconnecting") && action.equals("connect")) {
            return "connected";
        }
        return state;
    }

    public static void simulate_network() {
        String state = "idle";
        String[] actions = {"connect", "send", "disconnect", "reconnect"};
        while (true) {
            String action = actions[0];
            System.arraycopy(actions, 1, actions, 0, actions.length - 1);
            actions[actions.length - 1] = action;
            state = transition(state, action);
        }
    }

    public static void main(String[] args) {
        simulate_network();
    }
}