public class sample_1140 {

    public static class ConnectionState {
        private String state;

        public ConnectionState(String state) {
            this.state = state;
        }

        public ConnectionState transition() {
            if (this.state.equals("CONNECTING")) {
                return new ConnectionState("OPEN");
            } else if (this.state.equals("OPEN")) {
                return new ConnectionState("CLOSED");
            } else if (this.state.equals("CLOSED")) {
                return new ConnectionState("RECONNECTING");
            } else {
                return new ConnectionState("CONNECTING");
            }
        }
    }

    public static class NetworkMonitor {
        private ConnectionState state;

        public NetworkMonitor() {
            this.state = new ConnectionState("CONNECTING");
        }

        public void monitor() {
            while (true) {
                this.state = this.state.transition();
                this.process_state();
            }
        }

        public void process_state() {
            if (this.state.state.equals("OPEN")) {
                this.handle_open();
            } else if (this.state.state.equals("CLOSED")) {
                this.handle_closed();
            } else if (this.state.state.equals("RECONNECTING")) {
                this.handle_reconnecting();
            }
        }

        public void handle_open() {
        }

        public void handle_closed() {
        }

        public void handle_reconnecting() {
        }
    }

    public static void main(String[] args) {
        NetworkMonitor monitor = new NetworkMonitor();
        monitor.monitor();
    }
}