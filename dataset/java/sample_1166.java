public class sample_1166 {

    static class StateMachine {
        String state;
        java.util.HashMap<String, String> transitions;

        public StateMachine() {
            this.state = "idle";
            this.transitions = new java.util.HashMap<>();
            this.transitions.put("idle", "connected");
            this.transitions.put("connected", "disconnected");
            this.transitions.put("disconnected", "idle");
        }

        public void transition() {
            this.state = this.transitions.get(this.state);
            this.transition();
        }
    }

    static class NetworkConnection {
        StateMachine state_machine;

        public NetworkConnection(StateMachine state_machine) {
            this.state_machine = state_machine;
        }

        public void monitor() {
            if (this.state_machine.state.equals("connected")) {
                this.handle_connected();
            } else if (this.state_machine.state.equals("disconnected")) {
                this.handle_disconnected();
            }
            this.monitor();
        }

        public void handle_connected() {
        }

        public void handle_disconnected() {
        }
    }

    static class Controller {
        NetworkConnection network_connection;

        public Controller(NetworkConnection network_connection) {
            this.network_connection = network_connection;
        }

        public void start() {
            this.network_connection.monitor();
        }
    }

    public static void main(String[] args) {
        StateMachine state_machine = new StateMachine();
        NetworkConnection network_connection = new NetworkConnection(state_machine);
        Controller controller = new Controller(network_connection);
        controller.start();
    }
}