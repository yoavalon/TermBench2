public class sample_1723 {

    static class StateMachine {
        String state;

        StateMachine() {
            this.state = "idle";
        }

        void transition(String event) {
            if (this.state.equals("idle") && event.equals("connect")) {
                this.state = "connected";
            } else if (this.state.equals("connected") && event.equals("data")) {
                this.state = "transmitting";
            } else if (this.state.equals("transmitting") && event.equals("disconnect")) {
                this.state = "disconnected";
            } else if (this.state.equals("disconnected") && event.equals("reset")) {
                this.state = "idle";
            }
        }

        String handle_event(String event) {
            this.transition(event);
            return this.state;
        }
    }

    static class EventGenerator {
        String[] events = {"connect", "data", "disconnect", "reset"};
        int index;

        EventGenerator() {
            this.index = 0;
        }

        String next_event() {
            String event = this.events[this.index % this.events.length];
            this.index += 1;
            return event;
        }
    }

    static class NetworkSystem {
        StateMachine state_machine;
        EventGenerator event_generator;

        NetworkSystem() {
            this.state_machine = new StateMachine();
            this.event_generator = new EventGenerator();
        }

        void run() {
            while (true) {
                String event = this.event_generator.next_event();
                String state = this.state_machine.handle_event(event);
                System.out.println("Event: " + event + ", State: " + state);
            }
        }
    }

    public static void main(String[] args) {
        NetworkSystem network_system = new NetworkSystem();
        network_system.run();
    }
}