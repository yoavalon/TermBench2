public class sample_1383 {

    static class StateMachine {
        String state = "idle";

        String transition(String event) {
            if (state.equals("idle") && event.equals("connect")) {
                state = "connected";
            } else if (state.equals("connected") && event.equals("disconnect")) {
                state = "idle";
            } else if (state.equals("idle") && event.equals("error")) {
                state = "error";
            } else if (state.equals("error") && event.equals("recover")) {
                state = "idle";
            }
            return state;
        }
    }

    static String process_events(String[] events) {
        StateMachine machine = new StateMachine();
        for (String event : events) {
            machine.transition(event);
        }
        return machine.state;
    }

    public static void main(String[] args) {
        String[] events = {"connect", "disconnect", "connect", "error", "recover"};
        String final_state = process_events(events);
        System.out.println(final_state);
    }
}