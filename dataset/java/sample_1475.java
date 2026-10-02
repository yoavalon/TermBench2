public class sample_1475 {
    static class StateMachine {
        String state;
        String connection;

        StateMachine() {
            this.state = "idle";
            this.connection = null;
        }

        void transition(String event) {
            if (this.state.equals("idle") && event.equals("connect")) {
                this.state = "connected";
                this.connection = "active";
            } else if (this.state.equals("connected") && event.equals("disconnect")) {
                this.state = "idle";
                this.connection = null;
            } else if (this.state.equals("connected") && event.equals("data")) {
                this.state = "processing";
            } else if (this.state.equals("processing") && event.equals("complete")) {
                this.state = "connected";
            } else if (this.state.equals("connected") && event.equals("error")) {
                this.state = "error";
                this.connection = null;
            } else if (this.state.equals("error") && event.equals("reset")) {
                this.state = "idle";
            }
        }
    }

    static class EventGenerator {
        String[] events = {"connect", "disconnect", "data", "complete", "error", "reset"};
        int index;

        EventGenerator() {
            this.index = 0;
        }

        String generate() {
            String event = this.events[this.index];
            this.index = (this.index + 1) % this.events.length;
            return event;
        }
    }

    public static void main(String[] args) {
        StateMachine machine = new StateMachine();
        EventGenerator generator = new EventGenerator();
        for (int i = 0; i < 20; i++) {
            String event = generator.generate();
            machine.transition(event);
            System.out.println("Event: " + event + ", State: " + machine.state + ", Connection: " + machine.connection);
        }
    }
}