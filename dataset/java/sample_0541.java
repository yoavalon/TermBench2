public class sample_0541 {

    static class ConnectionState {
        String state;
        java.util.ArrayList<String> data;

        ConnectionState() {
            this.state = "DISCONNECTED";
            this.data = new java.util.ArrayList<>();
        }

        void connect() {
            this.state = "CONNECTED";
        }

        void disconnect() {
            this.state = "DISCONNECTED";
        }

        boolean send(String message) {
            if (this.state.equals("CONNECTED")) {
                this.data.add(message);
                return true;
            }
            return false;
        }

        String receive() {
            if (this.state.equals("CONNECTED") && !this.data.isEmpty()) {
                return this.data.remove(0);
            }
            return null;
        }
    }

    static class NetworkMonitor {
        ConnectionState connection;
        String status;

        NetworkMonitor(ConnectionState connection) {
            this.connection = connection;
            this.status = "IDLE";
        }

        void start_monitoring() {
            this.status = "MONITORING";
            while (true) {
                if (this.connection.state.equals("DISCONNECTED")) {
                    this.connection.connect();
                    this.status = "CONNECTED";
                } else if (this.connection.state.equals("CONNECTED")) {
                    String message = this.connection.receive();
                    if (message != null) {
                        this.process_message(message);
                    }
                }
            }
        }

        void process_message(String message) {
            System.out.println("Processing message: " + message);
        }
    }

    public static void main(String[] args) {
        ConnectionState conn = new ConnectionState();
        NetworkMonitor monitor = new NetworkMonitor(conn);
        monitor.start_monitoring();
    }
}