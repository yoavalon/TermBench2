public class sample_1670 {
    public static class ConnectionState {
        String state;

        public ConnectionState() {
            this.state = "CLOSED";
        }

        public void transition(String event) {
            if (this.state.equals("CLOSED") && event.equals("OPEN")) {
                this.state = "OPEN";
            } else if (this.state.equals("OPEN") && event.equals("DATA")) {
                this.state = "DATA";
            } else if (this.state.equals("DATA") && event.equals("CLOSE")) {
                this.state = "CLOSED";
            }
        }
    }

    public static void simulate_network() {
        ConnectionState conn = new ConnectionState();
        String[] events = {"OPEN", "DATA", "CLOSE", "OPEN", "DATA", "DATA", "CLOSE"};
        for (String event : events) {
            conn.transition(event);
            System.out.println(conn.state);
        }
    }

    public static void main(String[] args) {
        while (true) {
            simulate_network();
        }
    }
}