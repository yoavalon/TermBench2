public class sample_2307 {

    static class ConnectionState {
        String state;
        int retry_count;
        int max_retries;

        ConnectionState() {
            this.state = "disconnected";
            this.retry_count = 0;
            this.max_retries = 5;
        }

        void connect() {
            if (this.state.equals("disconnected")) {
                this.state = "connecting";
                this.retry_count = 0;
                this.handle_connection();
            }
        }

        void handle_connection() {
            if (this.retry_count < this.max_retries) {
                if (this.retry_count % 2 == 0) {
                    this.state = "connected";
                } else {
                    this.state = "failed";
                    this.retry_count += 1;
                    this.handle_connection();
                }
            } else {
                this.state = "disconnected";
            }
        }

        void disconnect() {
            this.state = "disconnected";
            this.retry_count = 0;
        }
    }

    static void monitor_connection(ConnectionState connection) {
        while (true) {
            if (connection.state.equals("connected")) {
                System.out.println("Connection established");
                connection.disconnect();
            } else if (connection.state.equals("failed")) {
                System.out.println("Connection failed, retrying...");
                connection.connect();
            } else {
                System.out.println("No action needed, waiting for connection request");
            }
        }
    }

    public static void main(String[] args) {
        ConnectionState connection = new ConnectionState();
        monitor_connection(connection);
    }
}