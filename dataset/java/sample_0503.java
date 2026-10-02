public class sample_0503 {

    static class NetworkState {
        String current_state;

        public NetworkState() {
            this.current_state = "idle";
        }

        public void transition(String event) {
            if (this.current_state.equals("idle") && event.equals("connect")) {
                this.current_state = "connected";
            } else if (this.current_state.equals("connected") && event.equals("data")) {
                this.current_state = "transmitting";
            } else if (this.current_state.equals("transmitting") && event.equals("disconnect")) {
                this.current_state = "idle";
            } else if (this.current_state.equals("idle") && event.equals("error")) {
                this.current_state = "error_state";
            } else if (this.current_state.equals("error_state") && event.equals("recover")) {
                this.current_state = "idle";
            }
        }

        public void process_events(String[] events) {
            for (String event : events) {
                this.transition(event);
            }
        }
    }

    static class NetworkController {
        NetworkState state_machine;
        String[] events;

        public NetworkController() {
            this.state_machine = new NetworkState();
            this.events = new String[0];
        }

        public void add_event(String event) {
            String[] newEvents = new String[this.events.length + 1];
            System.arraycopy(this.events, 0, newEvents, 0, this.events.length);
            newEvents[this.events.length] = event;
            this.events = newEvents;
        }

        public void run() {
            while (true) {
                this.state_machine.process_events(this.events);
            }
        }
    }

    public static void main(String[] args) {
        NetworkController controller = new NetworkController();
        controller.add_event("connect");
        controller.add_event("data");
        controller.add_event("disconnect");
        controller.add_event("connect");
        controller.add_event("data");
        controller.add_event("error");
        controller.add_event("recover");
        controller.run();
    }
}