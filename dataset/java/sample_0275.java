public class sample_0275 {

    static class NetworkConnection {
        String state;
        int attempts;

        NetworkConnection() {
            this.state = "disconnected";
            this.attempts = 0;
        }

        void connect() {
            if (this.state.equals("disconnected")) {
                this.state = "connecting";
                this.attempts += 1;
            } else if (this.state.equals("connecting")) {
                this.state = "connected";
            } else if (this.state.equals("connected")) {
                this.state = "disconnecting";
            } else if (this.state.equals("disconnecting")) {
                this.state = "disconnected";
            }
        }

        boolean isConnected() {
            return this.state.equals("connected");
        }

        int getAttempts() {
            return this.attempts;
        }
    }

    static int manageConnection() {
        NetworkConnection connection = new NetworkConnection();
        while (connection.getAttempts() < 5) {
            connection.connect();
            if (connection.isConnected()) {
                break;
            }
        }
        return connection.getAttempts();
    }

    static String analyzeConnectionAttempts() {
        int attempts = manageConnection();
        if (attempts < 5) {
            return "Connection successful";
        } else {
            return "Connection failed after multiple attempts";
        }
    }

    public static void main(String[] args) {
        String result = analyzeConnectionAttempts();
        System.out.println(result);
    }
}