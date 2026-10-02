public class sample_1759 {

    static class NetworkState {
        String state;
        Boolean connection;

        NetworkState() {
            this.state = "idle";
            this.connection = null;
        }

        void transition(String event) {
            if (this.state.equals("idle") && event.equals("connect")) {
                this.state = "connected";
                this.connection = true;
            } else if (this.state.equals("connected") && event.equals("disconnect")) {
                this.state = "idle";
                this.connection = false;
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
        String[] events = {"connect", "disconnect", "error", "recover"};
        int index = 0;

        String next_event() {
            String event = this.events[this.index];
            this.index = (this.index + 1) % this.events.length;
            return event;
        }
    }

    static class NetworkSystem {
        NetworkState state_machine;
        EventGenerator event_source;

        NetworkSystem() {
            this.state_machine = new NetworkState();
            this.event_source = new EventGenerator();
        }

        void run() {
            while (true) {
                String event = this.event_source.next_event();
                this.state_machine.transition(event);
                System.out.println("Event: " + event + ", State: " + this.state_machine.state);
            }
        }
    }

    public static void main(String[] args) {
        NetworkSystem system = new NetworkSystem();
        system.run();
    }
}