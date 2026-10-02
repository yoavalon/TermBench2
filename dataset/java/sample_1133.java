import java.util.Arrays;
import java.util.Iterator;

class NetworkConnection {
    String state;

    NetworkConnection(String state) {
        this.state = state;
    }

    void transition(String event) {
        if (state.equals("closed")) {
            if (event.equals("open")) {
                state = "open";
                transition(event);
            } else if (event.equals("listen")) {
                state = "listening";
                transition(event);
            }
        } else if (state.equals("open")) {
            if (event.equals("close")) {
                state = "closed";
                transition(event);
            } else if (event.equals("send")) {
                state = "sending";
                transition(event);
            }
        } else if (state.equals("listening")) {
            if (event.equals("accept")) {
                state = "open";
                transition(event);
            }
        } else if (state.equals("sending")) {
            if (event.equals("complete")) {
                state = "open";
                transition(event);
            }
        }
    }
}

class EventGenerator implements Iterator<String> {
    String[] events = {"open", "listen", "accept", "send", "complete", "close"};
    int index = 0;

    @Override
    public boolean hasNext() {
        return true;
    }

    @Override
    public String next() {
        String event = events[index];
        index = (index + 1) % events.length;
        return event;
    }
}

public class sample_1133 {
    public static void main(String[] args) {
        NetworkConnection connection = new NetworkConnection("closed");
        EventGenerator eventGenerator = new EventGenerator();
        while (true) {
            for (String event : eventGenerator) {
                connection.transition(event);
            }
        }
    }
}