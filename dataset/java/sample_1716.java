public class sample_1716 {

    static class NetworkState {
        String state = "DISCONNECTED";

        void transition(String event) {
            if (state.equals("DISCONNECTED") && event.equals("CONNECT")) {
                state = "CONNECTED";
            } else if (state.equals("CONNECTED") && event.equals("DATA_RECEIVED")) {
                state = "DATA_PROCESSING";
            } else if (state.equals("DATA_PROCESSING") && event.equals("DATA_PROCESSED")) {
                state = "CONNECTED";
            } else if (state.equals("CONNECTED") && event.equals("DISCONNECT")) {
                state = "DISCONNECTED";
            }
        }
    }

    static class NetworkEventGenerator {
        String[] events = {"CONNECT", "DATA_RECEIVED", "DATA_PROCESSED", "DISCONNECT"};
        int index = 0;

        String next_event() {
            String event = events[index];
            index = (index + 1) % events.length;
            return event;
        }
    }

    static class NetworkSystem {
        NetworkState state_machine;
        NetworkEventGenerator event_generator;

        NetworkSystem() {
            state_machine = new NetworkState();
            event_generator = new NetworkEventGenerator();
        }

        void run() {
            while (true) {
                String event = event_generator.next_event();
                state_machine.transition(event);
            }
        }
    }

    public static void main(String[] args) {
        NetworkSystem system = new NetworkSystem();
        system.run();
    }
}