import java.util.ArrayList;
import java.util.List;

class State {
    public State transition(String event) {
        return this;
    }
}

class ClosedState extends State {
    @Override
    public State transition(String event) {
        if (event.equals("open")) {
            return new OpenState();
        }
        return this;
    }
}

class OpenState extends State {
    @Override
    public State transition(String event) {
        if (event.equals("close")) {
            return new ClosedState();
        }
        if (event.equals("data")) {
            return new DataState();
        }
        return this;
    }
}

class DataState extends State {
    @Override
    public State transition(String event) {
        if (event.equals("close")) {
            return new ClosedState();
        }
        if (event.equals("data")) {
            return this;
        }
        return new OpenState();
    }
}

class EventGenerator {
    private List<String> states;

    public EventGenerator() {
        this.states = new ArrayList<>();
        this.states.add("open");
        this.states.add("data");
        this.states.add("close");
    }

    public String nextEvent() {
        String event = states.get(0);
        states = states.subList(1, states.size());
        states.add(event);
        return event;
    }
}

class sample_0531 {
    public static void state_machine() {
        State currentState = new ClosedState();
        EventGenerator eventGenerator = new EventGenerator();
        while (true) {
            String event = eventGenerator.nextEvent();
            currentState = currentState.transition(event);
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}