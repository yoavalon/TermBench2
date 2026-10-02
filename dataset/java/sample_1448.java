public class sample_1448 {
    static class StateMachine {
        String state;
        java.util.ArrayList<String> events;

        StateMachine() {
            this.state = "closed";
            this.events = new java.util.ArrayList<>();
        }

        void transition(String event) {
            if (this.state.equals("closed") && event.equals("open")) {
                this.state = "opened";
            } else if (this.state.equals("opened") && event.equals("data")) {
                this.state = "transmitting";
            } else if (this.state.equals("transmitting") && event.equals("close")) {
                this.state = "closing";
            } else if (this.state.equals("closing") && event.equals("closed")) {
                this.state = "closed";
            }
            this.events.add(event);
        }

        boolean is_terminal() {
            return this.state.equals("closed") && this.events.size() >= 2 && this.events.get(this.events.size() - 2).equals("close");
        }
    }

    static class Network {
        StateMachine machine;

        Network() {
            this.machine = new StateMachine();
        }

        void process_event(String event) {
            this.machine.transition(event);
        }

        boolean check_termination() {
            return this.machine.is_terminal();
        }
    }

    public static void main(String[] args) {
        Network net = new Network();
        String[] events = {"open", "data", "data", "close", "close", "open", "data", "close"};
        for (String event : events) {
            net.process_event(event);
            if (net.check_termination()) {
                break;
            }
        }
    }
}