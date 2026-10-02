public class sample_1709 {

    static class ConnectionState {
        private String state;

        public ConnectionState() {
            this.state = "disconnected";
        }

        public void transition(String event) {
            if (this.state.equals("disconnected") && event.equals("connect")) {
                this.state = "connected";
            } else if (this.state.equals("connected") && event.equals("disconnect")) {
                this.state = "disconnected";
            } else if (this.state.equals("connected") && event.equals("data")) {
                this.state = "processing";
            } else if (this.state.equals("processing") && event.equals("complete")) {
                this.state = "connected";
            } else if (this.state.equals("processing") && event.equals("error")) {
                this.state = "error";
            }
        }

        public String get_state() {
            return this.state;
        }
    }

    static class NetworkManager {
        private ConnectionState connection;
        private String[] events = {"connect", "disconnect", "data", "complete", "error"};
        private int event_index;

        public NetworkManager() {
            this.connection = new ConnectionState();
            this.event_index = 0;
        }

        public String generate_event() {
            String event = this.events[this.event_index % this.events.length];
            this.event_index += 1;
            return event;
        }

        public void simulate_network() {
            while (true) {
                String event = this.generate_event();
                this.connection.transition(event);
                System.out.println("Event: " + event + ", State: " + this.connection.get_state());
            }
        }
    }

    public static void main(String[] args) {
        NetworkManager network_manager = new NetworkManager();
        network_manager.simulate_network();
    }
}