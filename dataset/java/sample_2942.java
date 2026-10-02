public class sample_2942 {

    static class NetworkState {
        String state;

        NetworkState() {
            this.state = "idle";
        }

        void transition(String event) {
            if (this.state.equals("idle") && event.equals("connect")) {
                this.state = "connected";
            } else if (this.state.equals("connected") && event.equals("disconnect")) {
                this.state = "idle";
            } else if (this.state.equals("idle") && event.equals("error")) {
                this.state = "error";
            } else if (this.state.equals("connected") && event.equals("error")) {
                this.state = "error";
            } else if (this.state.equals("error") && event.equals("recover")) {
                this.state = "idle";
            }
        }
    }

    static class EventGenerator {
        String[] event_sequence = {"connect", "data", "disconnect", "connect", "data", "error", "recover"};
        int index = 0;

        String next_event() {
            return index < event_sequence.length ? event_sequence[index++] : null;
        }
    }

    static class NetworkSystem {
        NetworkState state_machine;
        EventGenerator event_generator;

        NetworkSystem() {
            this.state_machine = new NetworkState();
            this.event_generator = new EventGenerator();
        }

        void process_events() {
            while (true) {
                String event = event_generator.next_event();
                if (event != null) {
                    state_machine.transition(event);
                    if (state_machine.state.equals("error")) {
                        handle_error();
                    }
                }
            }
        }

        void handle_error() {
            System.out.println("Error state reached, attempting recovery...");
            state_machine.transition("recover");
        }
    }

    public static void main(String[] args) {
        NetworkSystem network_system = new NetworkSystem();
        network_system.process_events();
    }
}