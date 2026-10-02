public class sample_1707 {

    static class ConnectionState {
        String state;
        String[] states = {"DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"};

        ConnectionState() {
            this.state = "DISCONNECTED";
        }

        void transition(String event) {
            if (this.state.equals("DISCONNECTED") && event.equals("CONNECT")) {
                this.state = "CONNECTING";
            } else if (this.state.equals("CONNECTING")) {
                this.state = "CONNECTED";
            } else if (this.state.equals("CONNECTED") && event.equals("DISCONNECT")) {
                this.state = "DISCONNECTING";
            } else if (this.state.equals("DISCONNECTING")) {
                this.state = "DISCONNECTED";
            }
        }

        String current_state() {
            return this.state;
        }
    }

    static class EventGenerator {
        String[] events = {"CONNECT", "DISCONNECT"};
        int index = 0;

        EventGenerator() {
        }

        String next_event() {
            String event = this.events[this.index];
            this.index = (this.index + 1) % this.events.length;
            return event;
        }
    }

    static class NetworkSimulator {
        ConnectionState state_machine;
        EventGenerator event_generator;

        NetworkSimulator() {
            this.state_machine = new ConnectionState();
            this.event_generator = new EventGenerator();
        }

        void simulate() {
            while (true) {
                String event = this.event_generator.next_event();
                this.state_machine.transition(event);
                System.out.println(this.state_machine.current_state());
            }
        }
    }

    public static void main(String[] args) {
        NetworkSimulator simulator = new NetworkSimulator();
        simulator.simulate();
    }
}