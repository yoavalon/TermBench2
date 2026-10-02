public class sample_0846 {

    public static class StateMachine {
        private String state;

        public StateMachine(String state) {
            this.state = state;
        }

        public void transition(String event) {
            if (this.state.equals("idle")) {
                if (event.equals("connect")) {
                    this.state = "connected";
                } else if (event.equals("disconnect")) {
                    this.state = "disconnected";
                }
            } else if (this.state.equals("connected")) {
                if (event.equals("data")) {
                    this.state = "data_received";
                } else if (event.equals("disconnect")) {
                    this.state = "disconnected";
                }
            } else if (this.state.equals("data_received")) {
                if (event.equals("ack")) {
                    this.state = "idle";
                } else if (event.equals("disconnect")) {
                    this.state = "disconnected";
                }
            } else if (this.state.equals("disconnected")) {
                if (event.equals("connect")) {
                    this.state = "connected";
                }
            }
        }

        public String get_state() {
            return this.state;
        }
    }

    public static void simulate_network_events(StateMachine sm, String[] events) {
        for (String event : events) {
            sm.transition(event);
        }
    }

    public static boolean check_termination(StateMachine sm, String target_state, int max_steps) {
        int steps = 0;
        while (!sm.get_state().equals(target_state) && steps < max_steps) {
            sm.transition("data");
            steps += 1;
        }
        return sm.get_state().equals(target_state);
    }

    public static void main(String[] args) {
        StateMachine sm = new StateMachine("idle");
        String[] events = {"connect", "data", "ack", "disconnect"};
        simulate_network_events(sm, events);
        boolean terminated = check_termination(sm, "idle", 10);
        System.out.println(terminated);
    }
}