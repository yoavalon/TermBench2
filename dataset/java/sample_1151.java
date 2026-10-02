public class sample_1151 {

    class ConnectionState {
        String status;

        ConnectionState(String status) {
            this.status = status;
        }

        String connect() {
            if (this.status.equals("disconnected")) {
                this.status = "connected";
                return "Connection established";
            }
            return "Already connected";
        }

        String disconnect() {
            if (this.status.equals("connected")) {
                this.status = "disconnected";
                return "Connection terminated";
            }
            return "Already disconnected";
        }

        String toggle() {
            if (this.status.equals("connected")) {
                this.status = "disconnected";
            } else {
                this.status = "connected";
            }
            return "Status toggled to " + this.status;
        }
    }

    class NetworkHandler {
        ConnectionState state;

        NetworkHandler() {
            this.state = new ConnectionState("disconnected");
        }

        void manage_connection() {
            while (true) {
                String action = decide_action();
                if (action.equals("connect")) {
                    state.connect();
                } else if (action.equals("disconnect")) {
                    state.disconnect();
                } else if (action.equals("toggle")) {
                    state.toggle();
                } else {
                    break;
                }
            }
        }

        String decide_action() {
            if (state.status.equals("connected")) {
                return "disconnect";
            } else {
                return "connect";
            }
        }
    }

    public static void main(String[] args) {
        sample_1151 handler = new sample_1151();
        handler.new NetworkHandler().manage_connection();
    }
}