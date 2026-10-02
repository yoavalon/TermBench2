import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0521 {

    static class NetworkStateMachine {
        private String state;
        private List<String> events;

        public NetworkStateMachine() {
            this.state = "disconnected";
            this.events = new ArrayList<>();
        }

        public void transition(String event) {
            if (this.state.equals("disconnected") && event.equals("connect")) {
                this.state = "connected";
                this.events.add(event);
            } else if (this.state.equals("connected") && event.equals("disconnect")) {
                this.state = "disconnected";
                this.events.add(event);
            } else if (this.state.equals("connected") && event.equals("data")) {
                this.state = "processing";
                this.events.add(event);
            } else if (this.state.equals("processing") && event.equals("complete")) {
                this.state = "connected";
                this.events.add(event);
            } else {
                this.events.add("invalid");
            }
        }

        public String get_state() {
            return this.state;
        }

        public List<String> get_events() {
            return this.events;
        }
    }

    static class EventGenerator {
        private String[] events;

        public EventGenerator() {
            this.events = new String[]{"connect", "data", "complete", "disconnect"};
        }

        public String generate() {
            Random random = new Random();
            return this.events[random.nextInt(this.events.length)];
        }
    }

    static class SystemMonitor {
        private NetworkStateMachine state_machine;
        private EventGenerator event_generator;

        public SystemMonitor(NetworkStateMachine state_machine, EventGenerator event_generator) {
            this.state_machine = state_machine;
            this.event_generator = event_generator;
        }

        public void run() {
            while (true) {
                String event = this.event_generator.generate();
                this.state_machine.transition(event);
            }
        }
    }

    public static void main(String[] args) {
        NetworkStateMachine state_machine = new NetworkStateMachine();
        EventGenerator event_generator = new EventGenerator();
        SystemMonitor monitor = new SystemMonitor(state_machine, event_generator);
        monitor.run();
    }
}