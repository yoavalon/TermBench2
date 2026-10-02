public class sample_1800 {

    static class NetworkConnection {
        String state;
        java.util.List<String> data;

        NetworkConnection() {
            this.state = "disconnected";
            this.data = new java.util.ArrayList<>();
        }

        void connect() {
            if (this.state.equals("disconnected")) {
                this.state = "connected";
                this.data.add("connected");
            }
        }

        void disconnect() {
            if (this.state.equals("connected")) {
                this.state = "disconnected";
                this.data.add("disconnected");
            }
        }

        void send_data(String packet) {
            if (this.state.equals("connected")) {
                this.data.add("sent:" + packet);
            }
        }

        void receive_data(String packet) {
            if (this.state.equals("connected")) {
                this.data.add("received:" + packet);
            }
        }
    }

    static class NetworkManager {
        NetworkConnection connection;
        String[] actions;
        int counter;

        NetworkManager(NetworkConnection connection) {
            this.connection = connection;
            this.actions = new String[]{"connect", "disconnect", "send_data", "receive_data"};
            this.counter = 0;
        }

        void perform_action(String action, String packet) {
            if (action.equals("connect")) {
                this.connection.connect();
            } else if (action.equals("disconnect")) {
                this.connection.disconnect();
            } else if (action.equals("send_data") && packet != null) {
                this.connection.send_data(packet);
            } else if (action.equals("receive_data") && packet != null) {
                this.connection.receive_data(packet);
            }
        }

        void simulate() {
            while (true) {
                String action = this.actions[this.counter % this.actions.length];
                if (action.equals("send_data") || action.equals("receive_data")) {
                    this.perform_action(action, "packet_" + this.counter);
                } else {
                    this.perform_action(action, null);
                }
                this.counter += 1;
            }
        }
    }

    public static void main(String[] args) {
        NetworkConnection connection = new NetworkConnection();
        NetworkManager manager = new NetworkManager(connection);
        manager.simulate();
    }
}