class NetworkState {
    String state;

    NetworkState(String state) {
        this.state = state;
    }

    String transition(String event) {
        if (this.state.equals("DISCONNECTED") && event.equals("CONNECT")) {
            return "CONNECTED";
        } else if (this.state.equals("CONNECTED") && event.equals("DISCONNECT")) {
            return "DISCONNECTED";
        } else if (this.state.equals("CONNECTED") && event.equals("RECEIVE")) {
            return "PROCESSING";
        } else if (this.state.equals("PROCESSING") && event.equals("SEND")) {
            return "CONNECTED";
        } else {
            return this.state;
        }
    }
}

class NetworkStateMachine {
    NetworkState current_state;

    NetworkStateMachine() {
        this.current_state = new NetworkState("DISCONNECTED");
    }

    String process_event(String event) {
        String new_state = this.current_state.transition(event);
        this.current_state = new NetworkState(new_state);
        return new_state;
    }
}

public class sample_1129 {
    static String[] generate_events() {
        String[] events = {"CONNECT", "RECEIVE", "SEND", "DISCONNECT"};
        String[] repeated_events = new String[events.length * 10];
        for (int i = 0; i < 10; i++) {
            System.arraycopy(events, 0, repeated_events, i * events.length, events.length);
        }
        return repeated_events;
    }

    static void simulate_network() {
        NetworkStateMachine state_machine = new NetworkStateMachine();
        String[] events = generate_events();
        int index = 0;
        while (true) {
            String event = events[index % events.length];
            String new_state = state_machine.process_event(event);
            index++;
            if (new_state.equals("PROCESSING")) {
                simulate_network();
            }
        }
    }

    public static void main(String[] args) {
        simulate_network();
    }
}