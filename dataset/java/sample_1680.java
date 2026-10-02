import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class sample_1680 {

    public static String state_transition(String state, String event) {
        if (state.equals("disconnected")) {
            if (event.equals("connect")) {
                return "connected";
            }
        } else if (state.equals("connected")) {
            if (event.equals("disconnect")) {
                return "disconnected";
            } else if (event.equals("data")) {
                return "data_received";
            }
        } else if (state.equals("data_received")) {
            if (event.equals("acknowledge")) {
                return "connected";
            }
        }
        return state;
    }

    public static Iterator<String> event_generator() {
        List<String> events = Arrays.asList("connect", "disconnect", "data", "acknowledge");
        return new Iterator<String>() {
            private int index = 0;

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
        };
    }

    public static void main(String[] args) {
        String current_state = "disconnected";
        Iterator<String> eventIterator = event_generator();
        while (true) {
            String event = eventIterator.next();
            current_state = state_transition(current_state, event);
            System.out.println("Event: " + event + ", State: " + current_state);
        }
    }
}