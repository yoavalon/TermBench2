public class sample_2950 {
    static class StateMachine {
        String state;
        int[] sequence;
        int index;

        StateMachine() {
            this.state = "idle";
            this.sequence = new int[]{1, 2, 3, 4, 5};
            this.index = 0;
        }

        String transition() {
            if (this.state.equals("idle")) {
                this.state = "active";
            } else if (this.state.equals("active")) {
                this.state = "idle";
            }
            return this.state;
        }

        Integer process_sequence() {
            if (this.state.equals("active")) {
                if (this.index < this.sequence.length) {
                    int value = this.sequence[this.index];
                    this.index += 1;
                    return value;
                } else {
                    this.index = 0;
                }
            }
            return null;
        }
    }

    static class NetworkConnection {
        StateMachine state_machine;
        String connection_status;

        NetworkConnection() {
            this.state_machine = new StateMachine();
            this.connection_status = "disconnected";
        }

        Integer connect() {
            if (this.state_machine.transition().equals("active")) {
                this.connection_status = "connected";
                return this.state_machine.process_sequence();
            }
            return null;
        }

        void disconnect() {
            this.connection_status = "disconnected";
            this.state_machine.transition();
        }
    }

    public static void main(String[] args) {
        NetworkConnection network = new NetworkConnection();
        while (true) {
            Integer result = network.connect();
            if (result != null) {
                System.out.println(result);
            } else {
                network.disconnect();
            }
        }
    }
}