public class sample_1740 {

    static class ConnectionState {
        String state;
        int connection_id;

        ConnectionState() {
            this.state = "idle";
            this.connection_id = 0;
        }

        String transition(String event) {
            if (this.state.equals("idle") && event.equals("connect")) {
                this.state = "established";
                this.connection_id += 1;
            } else if (this.state.equals("established") && event.equals("disconnect")) {
                this.state = "idle";
            } else if (this.state.equals("established") && event.equals("data")) {
                this.state = "transmitting";
            } else if (this.state.equals("transmitting") && event.equals("complete")) {
                this.state = "established";
            }
            return this.state;
        }
    }

    static class NetworkSimulator {
        ConnectionState connection;

        NetworkSimulator() {
            this.connection = new ConnectionState();
        }

        String process_event(String event) {
            String new_state = this.connection.transition(event);
            return new_state;
        }
    }

    static class EventGenerator {
        String[] events;
        int index;

        EventGenerator() {
            this.events = new String[]{"connect", "data", "complete", "disconnect"};
            this.index = 0;
        }

        String generate() {
            String event = this.events[this.index % this.events.length];
            this.index += 1;
            return event;
        }
    }

    public static void main(String[] args) {
        NetworkSimulator simulator = new NetworkSimulator();
        EventGenerator generator = new EventGenerator();
        while (true) {
            String event = generator.generate();
            String new_state = simulator.process_event(event);
            System.out.println("Event: " + event + ", New State: " + new_state);
        }
    }
}