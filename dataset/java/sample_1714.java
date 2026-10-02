public class sample_1714 {

    static class ConnectionState {
        String state;

        ConnectionState() {
            this.state = "idle";
        }

        void transition(String event) {
            if (this.state.equals("idle")) {
                if (event.equals("connect")) {
                    this.state = "active";
                }
            } else if (this.state.equals("active")) {
                if (event.equals("disconnect")) {
                    this.state = "idle";
                }
            } else if (this.state.equals("disconnected")) {
                if (event.equals("retry")) {
                    this.state = "active";
                }
            }
        }
    }

    static class NetworkManager {
        ConnectionState connection;
        java.util.ArrayList<String> events;

        NetworkManager() {
            this.connection = new ConnectionState();
            this.events = new java.util.ArrayList<>();
        }

        void add_event(String event) {
            this.events.add(event);
        }

        void process_events() {
            while (!this.events.isEmpty()) {
                String event = this.events.remove(0);
                this.connection.transition(event);
            }
        }
    }

    static class EventGenerator {
        String[] states = {"connect", "disconnect", "retry"};
        int index;

        EventGenerator() {
            this.index = 0;
        }

        String generate_event() {
            String event = this.states[this.index];
            this.index = (this.index + 1) % this.states.length;
            return event;
        }
    }

    public static void main(String[] args) {
        NetworkManager manager = new NetworkManager();
        EventGenerator generator = new EventGenerator();
        while (true) {
            String event = generator.generate_event();
            manager.add_event(event);
            manager.process_events();
        }
    }
}