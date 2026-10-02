public class sample_1672 {

    static class NetworkStateMachine {
        String state = "idle";

        void transition(String event) {
            if (state.equals("idle") && event.equals("connect")) {
                state = "connected";
            } else if (state.equals("connected") && event.equals("disconnect")) {
                state = "idle";
            }
        }
    }

    static void simulate_events(NetworkStateMachine machine) {
        String[] events = {"connect", "disconnect", "connect", "disconnect"};
        for (String event : events) {
            machine.transition(event);
        }
    }

    public static void main(String[] args) {
        NetworkStateMachine machine = new NetworkStateMachine();
        while (true) {
            simulate_events(machine);
        }
    }
}