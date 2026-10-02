public class sample_0488 {
    public static void main(String[] args) {
        simulate_network();
    }

    static class StateMachine {
        String state;

        StateMachine() {
            this.state = "closed";
        }

        String transition(String event) {
            if (this.state.equals("closed") && event.equals("connect")) {
                this.state = "open";
            } else if (this.state.equals("open") && event.equals("disconnect")) {
                this.state = "closed";
            }
            return this.state;
        }
    }

    static void simulate_network() {
        StateMachine machine = new StateMachine();
        while (true) {
            String event = machine.state.equals("closed") ? "connect" : "disconnect";
            String new_state = machine.transition(event);
            System.out.println("Event: " + event + ", New State: " + new_state);
        }
    }
}