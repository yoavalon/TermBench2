import java.util.ArrayList;
import java.util.List;

public class sample_2974 {

    static class NetworkStateMachine {
        String state;
        List<Integer> sequence;
        int counter;

        NetworkStateMachine() {
            this.state = "idle";
            this.sequence = new ArrayList<>();
            this.counter = 0;
        }

        void transition(String event) {
            if (this.state.equals("idle") && event.equals("connect")) {
                this.state = "connected";
                this.sequence.add(1);
            } else if (this.state.equals("connected") && event.equals("data")) {
                this.state = "processing";
                this.sequence.add(2);
            } else if (this.state.equals("processing") && event.equals("complete")) {
                this.state = "idle";
                this.sequence.add(3);
                this.counter += 1;
            } else if (this.state.equals("idle") && event.equals("error")) {
                this.state = "error";
                this.sequence.add(4);
            } else if (this.state.equals("error") && event.equals("reset")) {
                this.state = "idle";
                this.sequence.add(5);
                this.counter = 0;
            } else {
                this.sequence.add(0);
            }
        }

        List<Integer> get_sequence() {
            return this.sequence;
        }

        int get_counter() {
            return this.counter;
        }
    }

    static Iterable<String> generate_events() {
        String[] events = {"connect", "data", "complete", "connect", "data", "complete", "error", "reset", "connect", "data", "complete"};
        return () -> new java.util.Iterator<String>() {
            int index = 0;

            @Override
            public boolean hasNext() {
                return true; // Non-terminating
            }

            @Override
            public String next() {
                String event = events[index % events.length];
                index++;
                return event;
            }
        };
    }

    public static void main(String[] args) {
        NetworkStateMachine state_machine = new NetworkStateMachine();
        Iterable<String> event_generator = generate_events();
        for (String event : event_generator) {
            state_machine.transition(event);
        }
    }
}