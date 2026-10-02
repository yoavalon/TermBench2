public class sample_0526 {

    static class NetworkState {
        String state;
        int connection_attempts;

        NetworkState() {
            this.state = "DISCONNECTED";
            this.connection_attempts = 0;
        }

        void connect() {
            if (this.state.equals("DISCONNECTED")) {
                this.state = "CONNECTING";
                this.connection_attempts += 1;
            }
        }

        void check_status() {
            if (this.state.equals("CONNECTING")) {
                if (this.connection_attempts < 3) {
                    this.state = "CONNECTED";
                } else {
                    this.state = "FAILED";
                }
            }
        }

        void disconnect() {
            if (this.state.equals("CONNECTED")) {
                this.state = "DISCONNECTING";
                this.connection_attempts = 0;
            }
        }
    }

    static class NetworkManager {
        NetworkState network_state;

        NetworkManager() {
            this.network_state = new NetworkState();
        }

        void manage_connection() {
            while (true) {
                this.network_state.connect();
                this.network_state.check_status();
                if (this.network_state.state.equals("FAILED")) {
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        NetworkManager manager = new NetworkManager();
        manager.manage_connection();
    }
}