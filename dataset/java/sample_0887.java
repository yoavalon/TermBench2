public class sample_0887 {

    static class State {
        String name;

        State(String name) {
            this.name = name;
        }

        State transition(String event, java.util.Map<String, State> states) {
            return this;
        }
    }

    static class OpenState extends State {
        OpenState(String name) {
            super(name);
        }

        @Override
        State transition(String event, java.util.Map<String, State> states) {
            if (event.equals("close")) {
                return states.get("closed");
            } else if (event.equals("error")) {
                return states.get("error");
            }
            return this;
        }
    }

    static class ClosedState extends State {
        ClosedState(String name) {
            super(name);
        }

        @Override
        State transition(String event, java.util.Map<String, State> states) {
            if (event.equals("open")) {
                return states.get("open");
            }
            return this;
        }
    }

    static class ErrorState extends State {
        ErrorState(String name) {
            super(name);
        }

        @Override
        State transition(String event, java.util.Map<String, State> states) {
            if (event.equals("recover")) {
                return states.get("open");
            }
            return this;
        }
    }

    static State process_events(State current_state, java.util.List<String> events, java.util.Map<String, State> states) {
        if (events.isEmpty()) {
            return current_state;
        }
        State next_state = current_state.transition(events.get(0), states);
        return process_events(next_state, events.subList(1, events.size()), states);
    }

    public static void main(String[] args) {
        OpenState open_state = new OpenState("open");
        ClosedState closed_state = new ClosedState("closed");
        ErrorState error_state = new ErrorState("error");
        java.util.Map<String, State> states = new java.util.HashMap<>();
        states.put("open", open_state);
        states.put("closed", closed_state);
        states.put("error", error_state);
        State current_state = states.get("closed");
        java.util.List<String> event_sequence = java.util.Arrays.asList("open", "data", "data", "close", "open", "error", "recover", "close");
        State final_state = process_events(current_state, event_sequence, states);
        System.out.println(final_state.name);
    }
}