public class sample_2997 {

    public static class StateMachine {
        private State[] states;
        private State current_state;

        public StateMachine(State[] states) {
            this.states = states;
            this.current_state = states[0];
        }

        public State transition(String event) {
            State new_state = this.current_state.next_state(event);
            for (State state : states) {
                if (state.equals(new_state)) {
                    this.current_state = new_state;
                    break;
                }
            }
            return this.current_state;
        }
    }

    public static class State {
        private String name;
        private java.util.Map<String, State> next_state_map;

        public State(String name, java.util.Map<String, State> next_state_map) {
            this.name = name;
            this.next_state_map = next_state_map;
        }

        public State next_state(String event) {
            return this.next_state_map.getOrDefault(event, this);
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            State state = (State) obj;
            return name.equals(state.name);
        }

        @Override
        public int hashCode() {
            return name.hashCode();
        }
    }

    public static class EventGenerator {
        private String[] events;
        private int index;

        public EventGenerator(String[] events) {
            this.events = events;
            this.index = 0;
        }

        public String next_event() {
            String event = this.events[this.index % this.events.length];
            this.index += 1;
            return event;
        }
    }

    public static void main(String[] args) {
        State state1 = new State("CONNECTING", java.util.Map.of("OK", new State("CONNECTED", java.util.Map.of()), "FAIL", new State("DISCONNECTED", java.util.Map.of())));
        State state2 = new State("CONNECTED", java.util.Map.of("LOSE", new State("DISCONNECTED", java.util.Map.of()), "KEEP", state1));
        State state3 = new State("DISCONNECTED", java.util.Map.of("RETRY", state1));
        State[] states = new State[]{state1, state2, state3};
        StateMachine sm = new StateMachine(states);
        String[] events = new String[]{"OK", "LOSE", "RETRY", "KEEP", "FAIL"};
        EventGenerator eg = new EventGenerator(events);
        while (true) {
            String event = eg.next_event();
            sm.transition(event);
        }
    }
}