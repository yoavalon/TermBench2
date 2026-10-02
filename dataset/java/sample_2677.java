public class sample_2677 {

    static class StateMachine {
        private final java.util.Map<String, java.util.List<String>> states;
        private final java.util.Map<java.util.AbstractMap.SimpleEntry<String, String>, String> transitions;
        private String currentState;
        private final java.util.List<String> sequence;

        public StateMachine(java.util.Map<String, java.util.List<String>> states, java.util.Map<java.util.AbstractMap.SimpleEntry<String, String>, String> transitions, String startState) {
            this.states = states;
            this.transitions = transitions;
            this.currentState = startState;
            this.sequence = new java.util.ArrayList<>();
        }

        public void transition(String event) {
            java.util.AbstractMap.SimpleEntry<String, String> key = new java.util.AbstractMap.SimpleEntry<>(currentState, event);
            if (transitions.containsKey(key)) {
                String nextState = transitions.get(key);
                currentState = nextState;
                sequence.add(event);
            } else {
                throw new java.lang.RuntimeException("Invalid transition");
            }
        }

        public boolean isTerminated() {
            java.util.List<String> terminalStates = states.getOrDefault("terminal", java.util.Collections.emptyList());
            return terminalStates.contains(currentState);
        }
    }

    static class NetworkConnection {
        private final StateMachine stateMachine;

        public NetworkConnection(StateMachine stateMachine) {
            this.stateMachine = stateMachine;
        }

        public void processEvents(java.util.List<String> events) {
            for (String event : events) {
                stateMachine.transition(event);
                if (stateMachine.isTerminated()) {
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        java.util.Map<String, java.util.List<String>> states = new java.util.HashMap<>();
        states.put("initial", java.util.Arrays.asList("connected", "disconnected"));
        states.put("connected", java.util.Arrays.asList("sending", "receiving", "disconnected"));
        states.put("sending", java.util.Arrays.asList("connected", "disconnected"));
        states.put("receiving", java.util.Arrays.asList("connected", "disconnected"));
        states.put("terminal", java.util.Arrays.asList("disconnected"));

        java.util.Map<java.util.AbstractMap.SimpleEntry<String, String>, String> transitions = new java.util.HashMap<>();
        transitions.put(new java.util.AbstractMap.SimpleEntry<>("initial", "connect"), "connected");
        transitions.put(new java.util.AbstractMap.SimpleEntry<>("connected", "send"), "sending");
        transitions.put(new java.util.AbstractMap.SimpleEntry<>("connected", "receive"), "receiving");
        transitions.put(new java.util.AbstractMap.SimpleEntry<>("connected", "disconnect"), "disconnected");
        transitions.put(new java.util.AbstractMap.SimpleEntry<>("sending", "connect"), "connected");
        transitions.put(new java.util.AbstractMap.SimpleEntry<>("sending", "disconnect"), "disconnected");
        transitions.put(new java.util.AbstractMap.SimpleEntry<>("receiving", "connect"), "connected");
        transitions.put(new java.util.AbstractMap.SimpleEntry<>("receiving", "disconnect"), "disconnected");

        String startState = "initial";
        StateMachine stateMachine = new StateMachine(states, transitions, startState);
        NetworkConnection networkConnection = new NetworkConnection(stateMachine);
        java.util.List<String> events = java.util.Arrays.asList("connect", "send", "receive", "disconnect");
        networkConnection.processEvents(events);
        System.out.println("Sequence: " + stateMachine.sequence);
        System.out.println("Terminated: " + stateMachine.isTerminated());
    }
}