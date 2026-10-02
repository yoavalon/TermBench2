public class sample_1004 {

    static class NetworkStateMachine {
        String state;

        NetworkStateMachine(String state) {
            this.state = state;
        }

        NetworkStateMachine transition() {
            if (this.state.equals("CONNECTING")) {
                this.state = "ESTABLISHED";
            } else if (this.state.equals("ESTABLISHED")) {
                this.state = "DISCONNECTING";
            } else if (this.state.equals("DISCONNECTING")) {
                this.state = "CONNECTING";
            }
            return this;
        }
    }

    static void recursive_process(NetworkStateMachine state_machine) {
        System.out.println(state_machine.state);
        state_machine.transition();
        recursive_process(state_machine);
    }

    public static void main(String[] args) {
        String initial_state = "CONNECTING";
        NetworkStateMachine state_machine = new NetworkStateMachine(initial_state);
        recursive_process(state_machine);
    }
}