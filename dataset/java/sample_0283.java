public class sample_0283 {

    static class NetworkStateMachine {
        String[] states;
        java.util.Map<java.util.List<String>, String> transitions;
        String current_state;

        NetworkStateMachine(String[] states, java.util.Map<java.util.List<String>, String> transitions) {
            this.states = states;
            this.transitions = transitions;
            this.current_state = states[0];
        }

        void transition(String event) {
            java.util.List<String> key = java.util.Arrays.asList(current_state, event);
            if (transitions.containsKey(key)) {
                current_state = transitions.get(key);
            } else {
                throw new java.lang.RuntimeException("Invalid transition");
            }
        }

        boolean is_terminal() {
            return java.util.Arrays.asList("disconnected", "error").contains(current_state);
        }
    }

    static class EventManager {
        String[] events;
        int index;

        EventManager(String[] events) {
            this.events = events;
            this.index = 0;
        }

        String get_next_event() {
            if (index < events.length) {
                String event = events[index];
                index += 1;
                return event;
            } else {
                return null;
            }
        }
    }

    public static void main(String[] args) {
        String[] states = {"idle", "connected", "disconnected", "error"};
        java.util.Map<java.util.List<String>, String> transitions = new java.util.HashMap<>();
        transitions.put(java.util.Arrays.asList("idle", "connect"), "connected");
        transitions.put(java.util.Arrays.asList("connected", "disconnect"), "disconnected");
        transitions.put(java.util.Arrays.asList("connected", "error"), "error");
        transitions.put(java.util.Arrays.asList("disconnected", "connect"), "connected");
        transitions.put(java.util.Arrays.asList("error", "reset"), "idle");
        String[] events = {"connect", "disconnect", "error", "reset", "connect", "disconnect", "connect", "error", "reset"};
        NetworkStateMachine network_machine = new NetworkStateMachine(states, transitions);
        EventManager event_manager = new EventManager(events);
        while (true) {
            String event = event_manager.get_next_event();
            if (event == null || network_machine.is_terminal()) {
                break;
            }
            network_machine.transition(event);
        }
        System.out.println("Final state: " + network_machine.current_state);
    }
}