import java.util.ArrayList;
import java.util.List;

public class sample_2951 {

    static class NetworkState {
        String state;
        List<Integer> sequence;

        NetworkState() {
            this.state = "disconnected";
            this.sequence = new ArrayList<>();
        }

        void transition(String event) {
            if (this.state.equals("disconnected")) {
                if (event.equals("connect")) {
                    this.state = "connected";
                    this.sequence.add(1);
                }
            } else if (this.state.equals("connected")) {
                if (event.equals("disconnect")) {
                    this.state = "disconnected";
                    this.sequence.add(0);
                } else if (event.equals("data_received")) {
                    this.sequence.add(2);
                } else if (event.equals("data_sent")) {
                    this.sequence.add(3);
                }
            }
        }

        List<Integer> get_sequence() {
            return this.sequence;
        }
    }

    static Iterable<String> event_generator() {
        return () -> new java.util.Iterator<>() {
            String[] events = {"connect", "data_received", "data_sent", "disconnect"};
            int index = 0;

            @Override
            public boolean hasNext() {
                return true; // Non-terminating
            }

            @Override
            public String next() {
                String event = events[index];
                index = (index + 1) % events.length;
                return event;
            }
        };
    }

    static void sequence_processor(NetworkState state_machine, Iterable<String> event_stream) {
        for (String event : event_stream) {
            state_machine.transition(event);
        }
    }

    public static void main(String[] args) {
        NetworkState state_machine = new NetworkState();
        Iterable<String> event_stream = event_generator();
        sequence_processor(state_machine, event_stream);
    }
}