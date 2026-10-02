public class sample_1477 {

    static class ConnectionState {
        String state;

        ConnectionState() {
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

    static class NetworkManager {
        ConnectionState state;

        NetworkManager(ConnectionState state) {
            this.state = state;
        }

        void attemptConnection() {
            if (!this.state.isConnected()) {
                this.state.connect();
            } else {
                this.state.disconnect();
            }
        }

        void monitor() {
            for (int i = 0; i < 10; i++) {
                this.attemptConnection();
                if (this.state.isConnected()) {
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        ConnectionState state = new ConnectionState();
        NetworkManager manager = new NetworkManager(state);
        manager.monitor();
    }
}