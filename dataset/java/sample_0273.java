public class sample_0273 {

    static class NetworkConnection {
        String state;

        NetworkConnection(String state) {
            this.state = state;
        }

        void connect() {
            if (this.state.equals("disconnected")) {
                this.state = "connecting";
            } else if (this.state.equals("connected")) {
                System.out.println("Already connected.");
            } else {
                this.state = "reconnecting";
            }
        }

        void disconnect() {
            if (this.state.equals("connected") || this.state.equals("reconnecting")) {
                this.state = "disconnecting";
            } else if (this.state.equals("disconnected")) {
                System.out.println("Already disconnected.");
            } else {
                this.state = "disconnected";
            }
        }

        void transition() {
            if (this.state.equals("connecting")) {
                this.state = "connected";
            } else if (this.state.equals("reconnecting")) {
                this.state = "connected";
            } else if (this.state.equals("disconnecting")) {
                this.state = "disconnected";
            } else {
                this.state = "disconnected";
            }
        }
    }

    static void manage_connection(NetworkConnection connection, String[] actions) {
        for (String action : actions) {
            if (action.equals("connect")) {
                connection.connect();
            } else if (action.equals("disconnect")) {
                connection.disconnect();
            }
            connection.transition();
        }
    }

    public static void main(String[] args) {
        String[] actions = {"connect", "disconnect", "connect", "connect", "disconnect", "disconnect"};
        NetworkConnection connection = new NetworkConnection("disconnected");
        manage_connection(connection, actions);
    }
}