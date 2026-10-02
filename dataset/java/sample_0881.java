public class sample_0881 {

    public static class ConnectionState {
        private String state;

        public ConnectionState() {
            this.state = "disconnected";
        }

        public String connect() {
            if (this.state.equals("disconnected")) {
                this.state = "connecting";
                return this.connecting();
            }
            return "already connected";
        }

        public String connecting() {
            if (this.state.equals("connecting")) {
                this.state = "connected";
                return this.connected();
            }
            return "connection failed";
        }

        public String connected() {
            if (this.state.equals("connected")) {
                this.state = "disconnecting";
                return this.disconnecting();
            }
            return "connection lost";
        }

        public String disconnecting() {
            if (this.state.equals("disconnecting")) {
                this.state = "disconnected";
                return "disconnected";
            }
            return "disconnection failed";
        }
    }

    public static String[] simulate_connections() {
        ConnectionState conn = new ConnectionState();
        String[] states = {"connect", "connect", "disconnect", "connect", "disconnect"};
        String[] results = new String[states.length];
        for (int i = 0; i < states.length; i++) {
            if (states[i].equals("connect")) {
                results[i] = conn.connect();
            } else if (states[i].equals("disconnect")) {
                results[i] = conn.disconnecting();
            }
        }
        return results;
    }

    public static void main(String[] args) {
        String[] results = simulate_connections();
        for (String result : results) {
            System.out.println(result);
        }
    }
}