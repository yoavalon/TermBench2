public class sample_2919 {

    static class NetworkState {
        String state;

        NetworkState() {
            this.state = "idle";
        }

        String transition(String event) {
            if (this.state.equals("idle") && event.equals("connect")) {
                this.state = "active";
            } else if (this.state.equals("active") && event.equals("disconnect")) {
                this.state = "idle";
            } else if (this.state.equals("active") && event.equals("data")) {
                this.state = "processing";
            } else if (this.state.equals("processing") && event.equals("complete")) {
                this.state = "active";
            } else if (this.state.equals("processing") && event.equals("error")) {
                this.state = "active";
            }
            return this.state;
        }
    }

    static class EventGenerator {
        String[] events = {"connect", "data", "complete", "error", "disconnect"};
        int index = 0;

        String get_event() {
            String event = this.events[this.index];
            this.index = (this.index + 1) % this.events.length;
            return event;
        }
    }

    static class NetworkSystem {
        NetworkState state_machine;
        EventGenerator event_generator;

        NetworkSystem() {
            this.state_machine = new NetworkState();
            this.event_generator = new EventGenerator();
        }

        void run() {
            while (true) {
                String event = this.event_generator.get_event();
                String new_state = this.state_machine.transition(event);
                System.out.println("Event: " + event + ", New State: " + new_state);
            }
        }
    }

    public static void main(String[] args) {
        NetworkSystem network_system = new NetworkSystem();
        network_system.run();
    }
}