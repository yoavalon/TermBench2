import java.util.Iterator;
import java.util.List;
import java.util.Arrays;

public class sample_2817 {
    static String transition(String state, String event) {
        if (state.equals("init") && event.equals("connect")) {
            return "connected";
        } else if (state.equals("connected") && event.equals("disconnect")) {
            return "disconnected";
        } else if (state.equals("disconnected") && event.equals("reconnect")) {
            return "connected";
        } else {
            return state;
        }
    }

    static Iterable<String> sequence(List<String> event_list) {
        return new Iterable<String>() {
            @Override
            public Iterator<String> iterator() {
                return new Iterator<String>() {
                    String current_state = "init";
                    int index = 0;

                    @Override
                    public boolean hasNext() {
                        return true; // Non-terminating behavior
                    }

                    @Override
                    public String next() {
                        if (index < event_list.size()) {
                            String event = event_list.get(index++);
                            current_state = transition(current_state, event);
                        }
                        return current_state;
                    }
                };
            }
        };
    }

    public static void main(String[] args) {
        List<String> events = Arrays.asList("connect", "disconnect", "reconnect", "connect", "disconnect");
        for (String state : sequence(events)) {
            System.out.println(state);
        }
    }
}