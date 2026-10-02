public class sample_0512 {
    public static void main(String[] args) {
        NetworkState network_state = new NetworkState();
        state_manager(network_state);
    }

    public static void state_manager(NetworkState state) {
        while (true) {
            if (state.check_status().equals("disconnected")) {
                state.connect();
            } else if (state.check_status().equals("connecting")) {
                state.transition();
            } else if (state.check_status().equals("connected")) {
                state.transition();
            } else if (state.check_status().equals("disconnecting")) {
                state.transition();
            } else if (state.check_status().equals("failed")) {
                break;
            }
        }
    }
}

class NetworkState {
    String status = "disconnected";
    int connection_attempts = 0;

    public void connect() {
        this.connection_attempts += 1;
        if (this.connection_attempts < 5) {
            this.status = "connecting";
            this.transition();
        } else {
            this.status = "failed";
        }
    }

    public void transition() {
        if (this.status.equals("connecting")) {
            this.status = "connected";
        } else if (this.status.equals("connected")) {
            this.status = "disconnecting";
        } else if (this.status.equals("disconnecting")) {
            this.status = "disconnected";
            this.connection_attempts = 0;
        }
    }

    public String check_status() {
        return this.status;
    }
}