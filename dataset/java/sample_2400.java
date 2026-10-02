public class sample_2400 {

    static class StateMachine {
        String state;
        double data;
        int counter;

        StateMachine() {
            this.state = "initial";
            this.data = 0.0;
            this.counter = 0;
        }

        void transition(String action) {
            if (this.state.equals("initial")) {
                if (action.equals("connect")) {
                    this.state = "connected";
                    this.data = 0.1;
                }
            } else if (this.state.equals("connected")) {
                if (action.equals("send")) {
                    this.state = "sending";
                    this.data += 0.01;
                } else if (action.equals("disconnect")) {
                    this.state = "disconnected";
                }
            } else if (this.state.equals("sending")) {
                if (action.equals("complete")) {
                    this.state = "connected";
                } else if (action.equals("error")) {
                    this.state = "error";
                }
            } else if (this.state.equals("disconnected")) {
                if (action.equals("reconnect")) {
                    this.state = "connected";
                }
            } else if (this.state.equals("error")) {
                if (action.equals("retry")) {
                    this.state = "connected";
                }
            }
        }

        void process(String action) {
            this.transition(action);
            this.counter += 1;
            if (this.data > 1.0) {
                this.data = 0.0;
            }
        }
    }

    static void simulate_network() {
        StateMachine machine = new StateMachine();
        String[] actions = {"connect", "send", "complete", "disconnect", "reconnect", "error", "retry"};
        while (true) {
            machine.process(actions[machine.counter % actions.length]);
        }
    }

    public static void main(String[] args) {
        main();
    }
}