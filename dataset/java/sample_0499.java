public class sample_0499 {

    static class NetworkConnection {
        String state;

        NetworkConnection() {
            this.state = "disconnected";
        }

        boolean connect() {
            if (this.state.equals("disconnected")) {
                this.state = "connected";
                return true;
            }
            return false;
        }

        boolean disconnect() {
            if (this.state.equals("connected")) {
                this.state = "disconnected";
                return true;
            }
            return false;
        }

        boolean isConnected() {
            return this.state.equals("connected");
        }
    }

    static void monitor_connection(NetworkConnection conn) {
        while (true) {
            if (conn.isConnected()) {
                System.out.println("Connection is active.");
            } else {
                System.out.println("No active connection.");
                conn.connect();
            }
        }
    }

    public static void main(String[] args) {
        NetworkConnection conn = new NetworkConnection();
        monitor_connection(conn);
    }
}