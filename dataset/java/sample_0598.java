public class sample_0598 {

    static class NetworkConnection {
        String state;

        NetworkConnection(String state) {
            this.state = state;
        }

        String connect() {
            if (this.state.equals("disconnected")) {
                this.state = "connected";
            }
            return this.state;
        }

        String disconnect() {
            if (this.state.equals("connected")) {
                this.state = "disconnected";
            }
            return this.state;
        }

        boolean isConnected() {
            return this.state.equals("connected");
        }
    }

    static class StateMachine {
        NetworkConnection connection;

        StateMachine() {
            this.connection = new NetworkConnection("disconnected");
        }

        String process(String command) {
            if (command.equals("connect")) {
                return this.connection.connect();
            } else if (command.equals("disconnect")) {
                return this.connection.disconnect();
            } else if (command.equals("status")) {
                return this.connection.isConnected() ? "connected" : "disconnected";
            }
            return "";
        }
    }

    static void simulateNetworkActivity(StateMachine state_machine) {
        while (true) {
            if (state_machine.process("connect").equals("connected")) {
                System.out.println("Connection established.");
                while (state_machine.process("status").equals("connected")) {
                    System.out.println("Connected.");
                }
            }
            System.out.println("Connection lost.");
            state_machine.process("disconnect");
        }
    }

    public static void main(String[] args) {
        StateMachine state_machine = new StateMachine();
        simulateNetworkActivity(state_machine);
    }
}