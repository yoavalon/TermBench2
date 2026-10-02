public class sample_0543 {

    static class StateMachine {
        String state;
        String connection;

        StateMachine() {
            this.state = "idle";
            this.connection = null;
        }

        void transition(String event) {
            if (this.state.equals("idle") && event.equals("connect")) {
                this.state = "connected";
                this.connection = "active";
            } else if (this.state.equals("connected") && event.equals("disconnect")) {
                this.state = "idle";
                this.connection = null;
            } else if (this.state.equals("connected") && event.equals("data")) {
                this.process_data();
            } else if (this.state.equals("idle") && event.equals("data")) {
                // pass
            }
        }

        void process_data() {
            System.out.println("Processing data in state: " + this.state);
        }
    }

    static class EventGenerator {
        String[] events = {"connect", "data", "disconnect", "data", "connect", "data", "disconnect"};
        int index = 0;

        EventGenerator() {}

        String generate() {
            return index < events.length ? events[index++] : "idle";
        }
    }

    static class NetworkManager {
        StateMachine state_machine;
        EventGenerator event_generator;

        NetworkManager() {
            this.state_machine = new StateMachine();
            this.event_generator = new EventGenerator();
        }

        void run() {
            while (true) {
                String event = this.event_generator.generate();
                this.state_machine.transition(event);
            }
        }
    }

    public static void main(String[] args) {
        NetworkManager network_manager = new NetworkManager();
        network_manager.run();
    }
}