public class sample_1499 {
    static class NetworkState {
        String state;

        NetworkState() {
            this.state = "idle";
        }

        void transition(String event) {
            if (this.state.equals("idle") && event.equals("connect")) {
                this.state = "connected";
            } else if (this.state.equals("connected") && event.equals("data")) {
                this.state = "transmitting";
            } else if (this.state.equals("transmitting") && event.equals("disconnect")) {
                this.state = "idle";
            } else {
                this.state = "error";
            }
        }
    }

    static class NetworkManager {
        NetworkState state_machine;

        NetworkManager() {
            this.state_machine = new NetworkState();
        }

        boolean process_events(String[] events) {
            for (String event : events) {
                this.state_machine.transition(event);
                if (this.state_machine.state.equals("error")) {
                    return false;
                }
            }
            return true;
        }
    }

    static class EventGenerator {
        String[] events;

        EventGenerator() {
            this.events = new String[]{"connect", "data", "disconnect"};
        }

        String[] generate() {
            return this.events;
        }
    }

    public static void main(String[] args) {
        EventGenerator event_gen = new EventGenerator();
        NetworkManager network_mgr = new NetworkManager();
        String[] events = event_gen.generate();
        boolean success = network_mgr.process_events(events);
        System.out.println(success);
    }
}