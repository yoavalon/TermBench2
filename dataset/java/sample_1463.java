public class sample_1463 {

    static class StateMachine {
        String state = "idle";
        boolean connection = false;

        void transition(String event) {
            if (state.equals("idle") && event.equals("connect")) {
                state = "connected";
                connection = true;
            } else if (state.equals("connected") && event.equals("disconnect")) {
                state = "idle";
                connection = false;
            } else if (state.equals("connected") && event.equals("error")) {
                state = "error";
                connection = false;
            } else if (state.equals("error") && event.equals("recover")) {
                state = "connected";
                connection = true;
            }
        }

        Object[] get_status() {
            return new Object[]{state, connection};
        }
    }

    static Object[] simulate_events(String[] events) {
        StateMachine machine = new StateMachine();
        Object[] statuses = new Object[events.length];
        for (int i = 0; i < events.length; i++) {
            machine.transition(events[i]);
            statuses[i] = machine.get_status();
        }
        return statuses;
    }

    public static void main(String[] args) {
        String[] events_sequence = {"connect", "data", "disconnect", "connect", "error", "recover"};
        Object[] results = simulate_events(events_sequence);
        for (Object status : results) {
            System.out.println(status);
        }
    }
}