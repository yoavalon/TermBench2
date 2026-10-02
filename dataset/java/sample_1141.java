public class sample_1141 {

    static class NetworkState {
        String state;
        String[] buffer = new String[100];
        int bufferSize = 0;

        NetworkState() {
            this.state = "idle";
        }

        void transition(String event) {
            if (this.state.equals("idle") && event.equals("connect")) {
                this.state = "connected";
                buffer[bufferSize++] = "connection established";
            } else if (this.state.equals("connected") && event.equals("data")) {
                this.state = "data_received";
                buffer[bufferSize++] = "data received";
            } else if (this.state.equals("data_received") && event.equals("disconnect")) {
                this.state = "idle";
                buffer[bufferSize++] = "disconnected";
            }
        }
    }

    static class NetworkHandler {
        NetworkState machine;

        NetworkHandler(NetworkState state_machine) {
            this.machine = state_machine;
        }

        void handle_event(String event) {
            this.machine.transition(event);
        }
    }

    static class NetworkMonitor {
        NetworkHandler handler;

        NetworkMonitor(NetworkHandler handler) {
            this.handler = handler;
        }

        void monitor() {
            String[] events = {"connect", "data", "disconnect"};
            while (true) {
                for (String event : events) {
                    this.handler.handle_event(event);
                }
            }
        }
    }

    public static void main(String[] args) {
        NetworkState state_machine = new NetworkState();
        NetworkHandler handler = new NetworkHandler(state_machine);
        NetworkMonitor monitor = new NetworkMonitor(handler);
        monitor.monitor();
    }
}