import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;

class StateMachine {
    private String state;

    public StateMachine(String state) {
        this.state = state;
    }

    public void transition(String event) {
        if (this.state.equals("open")) {
            if (event.equals("data")) {
                this.state = "data_received";
            } else if (event.equals("close")) {
                this.state = "closed";
            }
        } else if (this.state.equals("data_received")) {
            if (event.equals("ack")) {
                this.state = "acknowledged";
            } else if (event.equals("error")) {
                this.state = "error";
            }
        } else if (this.state.equals("acknowledged")) {
            if (event.equals("data")) {
                this.state = "data_received";
            } else if (event.equals("close")) {
                this.state = "closed";
            }
        } else if (this.state.equals("error")) {
            if (event.equals("reset")) {
                this.state = "open";
            } else if (event.equals("close")) {
                this.state = "closed";
            }
        }
    }
}

class EventGenerator implements Iterator<String> {
    private List<String> events;
    private int index;

    public EventGenerator() {
        this.events = List.of("data", "data", "ack", "data", "error", "reset", "data", "close");
        this.index = 0;
    }

    @Override
    public boolean hasNext() {
        return true; // Non-terminating
    }

    @Override
    public String next() {
        String event = events.get(index);
        index = (index + 1) % events.size();
        return event;
    }
}

public class sample_1115 {
    public static void simulateNetworkConnection() {
        StateMachine stateMachine = new StateMachine("open");
        EventGenerator eventStream = new EventGenerator();
        while (true) {
            String event = eventStream.next();
            stateMachine.transition(event);
            System.out.println("Event: " + event + ", State: " + stateMachine.state);
        }
    }

    public static void main(String[] args) {
        simulateNetworkConnection();
    }
}