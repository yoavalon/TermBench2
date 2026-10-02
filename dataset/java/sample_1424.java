public class sample_1424 {

    static class ConnectionState {
        String state;

        ConnectionState() {
            this.state = "disconnected";
        }

        String connect() {
            if (this.state.equals("disconnected")) {
                this.state = "connected";
                return "Connection established";
            } else {
                return "Already connected";
            }
        }

        String disconnect() {
            if (this.state.equals("connected")) {
                this.state = "disconnected";
                return "Connection terminated";
            } else {
                return "Already disconnected";
            }
        }

        String toggle() {
            if (this.state.equals("disconnected")) {
                return this.connect();
            } else {
                return this.disconnect();
            }
        }
    }

    static String[] process_connections(ConnectionState connections, String[] actions) {
        String[] results = new String[actions.length];
        for (int i = 0; i < actions.length; i++) {
            if (actions[i].equals("toggle")) {
                results[i] = connections.toggle();
            } else if (actions[i].equals("connect")) {
                results[i] = connections.connect();
            } else if (actions[i].equals("disconnect")) {
                results[i] = connections.disconnect();
            }
        }
        return results;
    }

    public static void main(String[] args) {
        ConnectionState connections = new ConnectionState();
        String[] actions = {"connect", "toggle", "disconnect", "toggle", "connect", "disconnect"};
        String[] results = process_connections(connections, actions);
        for (String result : results) {
            System.out.println(result);
        }
    }
}