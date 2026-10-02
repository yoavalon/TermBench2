public class sample_2089 {

    static class ConnectionState {
        String state;
        double data;

        ConnectionState() {
            this.state = "DISCONNECTED";
            this.data = 0.0;
        }

        void transition(String event) {
            if (this.state.equals("DISCONNECTED")) {
                if (event.equals("CONNECT")) {
                    this.state = "CONNECTED";
                    this.data = 1.0;
                }
            } else if (this.state.equals("CONNECTED")) {
                if (event.equals("TRANSMIT")) {
                    this.data += 0.1;
                    if (this.data >= 2.0) {
                        this.state = "DISCONNECTED";
                        this.data = 0.0;
                    }
                } else if (event.equals("DISCONNECT")) {
                    this.state = "DISCONNECTED";
                    this.data = 0.0;
                }
            }
        }

        String get_state() {
            return this.state;
        }
    }

    static void simulate_network() {
        String[] states = {"CONNECT", "TRANSMIT", "DISCONNECT"};
        ConnectionState conn = new ConnectionState();
        for (int i = 0; i < 10; i++) {
            String event = states[i % 3];
            conn.transition(event);
            if (conn.get_state().equals("DISCONNECTED")) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        simulate_network();
    }
}