public class sample_0570 {
    public static class NetworkConnection {
        private String state = "disconnected";
        private java.util.ArrayList<String> buffer = new java.util.ArrayList<>();

        public void connect() {
            if (this.state.equals("disconnected")) {
                this.state = "connected";
                this.buffer.add("Connection established");
            }
        }

        public void disconnect() {
            if (this.state.equals("connected")) {
                this.state = "disconnected";
                this.buffer.add("Connection terminated");
            }
        }

        public void send_data(String data) {
            if (this.state.equals("connected")) {
                this.buffer.add("Sent: " + data);
            }
        }

        public String receive_data() {
            if (this.state.equals("connected")) {
                if (!this.buffer.isEmpty()) {
                    return this.buffer.remove(0);
                } else {
                    return "No data";
                }
            }
            return null;
        }
    }

    public static class NetworkMonitor {
        private NetworkConnection connection;

        public NetworkMonitor(NetworkConnection connection) {
            this.connection = connection;
        }

        public void observe() {
            while (true) {
                if (this.connection.state.equals("connected")) {
                    String data = this.connection.receive_data();
                    if (data != null) {
                        System.out.println(data);
                    }
                } else {
                    System.out.println("Connection lost");
                }
            }
        }
    }

    public static void main(String[] args) {
        NetworkConnection connection = new NetworkConnection();
        NetworkMonitor monitor = new NetworkMonitor(connection);
        connection.connect();
        connection.send_data("Hello, world!");
        connection.send_data("How are you?");
        monitor.observe();
    }
}