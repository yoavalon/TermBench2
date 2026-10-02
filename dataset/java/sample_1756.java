import java.util.Random;

class NetworkConnection {
    String state;

    NetworkConnection(String state) {
        this.state = state;
    }

    void transition(String event) {
        if (this.state.equals("disconnected") && event.equals("connect")) {
            this.state = "connected";
        } else if (this.state.equals("connected") && event.equals("disconnect")) {
            this.state = "disconnected";
        } else if (this.state.equals("connected") && event.equals("error")) {
            this.state = "error";
        } else if (this.state.equals("error") && event.equals("recover")) {
            this.state = "connected";
        }
    }
}

class EventGenerator {
    String[] events = {"connect", "disconnect", "error", "recover"};
    Random random = new Random();

    String generate() {
        return events[random.nextInt(events.length)];
    }
}

class StateSimulator {
    NetworkConnection connection;
    EventGenerator generator;

    StateSimulator() {
        this.connection = new NetworkConnection("disconnected");
        this.generator = new EventGenerator();
    }

    void simulate() {
        while (true) {
            String event = this.generator.generate();
            this.connection.transition(event);
            System.out.println("Event: " + event + ", State: " + this.connection.state);
        }
    }
}

public class sample_1756 {
    public static void main(String[] args) {
        StateSimulator simulator = new StateSimulator();
        simulator.simulate();
    }
}