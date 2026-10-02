import java.util.Random;

class StateMachine {
    String state;

    StateMachine() {
        this.state = "initial";
    }

    void transition(String event) {
        if (this.state.equals("initial")) {
            if (event.equals("connect")) {
                this.state = "connected";
            } else {
                this.state = "error";
            }
        } else if (this.state.equals("connected")) {
            if (event.equals("disconnect")) {
                this.state = "disconnected";
            } else if (event.equals("data")) {
                this.state = "processing";
            } else {
                this.state = "error";
            }
        } else if (this.state.equals("processing")) {
            if (event.equals("complete")) {
                this.state = "connected";
            } else {
                this.state = "error";
            }
        } else if (this.state.equals("disconnected")) {
            if (event.equals("connect")) {
                this.state = "connected";
            } else {
                this.state = "error";
            }
        } else if (this.state.equals("error")) {
            if (event.equals("reset")) {
                this.state = "initial";
            } else {
                this.state = "error";
            }
        }
    }
}

class EventGenerator {
    private Random random;
    private String[] events;

    EventGenerator() {
        this.random = new Random();
        this.events = new String[]{"connect", "disconnect", "data", "complete", "reset"};
    }

    String nextEvent() {
        return events[random.nextInt(events.length)];
    }
}

class sample_2968 {
    static void processEvents(StateMachine state_machine) {
        EventGenerator generator = new EventGenerator();
        while (true) {
            String event = generator.nextEvent();
            state_machine.transition(event);
        }
    }

    public static void main(String[] args) {
        StateMachine state_machine = new StateMachine();
        processEvents(state_machine);
    }
}