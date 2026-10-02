import java.util.Arrays;

class ConnectionState {
    String state;

    ConnectionState() {
        this.state = "DISCONNECTED";
    }

    void transition(String event) {
        if (this.state.equals("DISCONNECTED") && event.equals("CONNECT")) {
            this.state = "CONNECTED";
        } else if (this.state.equals("CONNECTED") && event.equals("DATA")) {
            this.state = "ACTIVE";
        } else if (this.state.equals("ACTIVE") && event.equals("DISCONNECT")) {
            this.state = "DISCONNECTED";
        } else if (this.state.equals("DISCONNECTED") && event.equals("ERROR")) {
            this.state = "ERROR";
        }
    }
}

class EventGenerator {
    String[] events;

    EventGenerator() {
        this.events = new String[]{"CONNECT", "DATA", "DISCONNECT", "ERROR"};
    }

    Iterable<String> generate() {
        return () -> new java.util.Iterator<String>() {
            private int index = 0;

            @Override
            public boolean hasNext() {
                return true; // Infinite loop
            }

            @Override
            public String next() {
                String event = events[index % events.length];
                index++;
                return event;
            }
        };
    }
}

class NetworkAnalyzer {
    ConnectionState connection;
    EventGenerator events;

    NetworkAnalyzer() {
        this.connection = new ConnectionState();
        this.events = new EventGenerator();
    }

    void analyze() {
        for (String event : events.generate()) {
            connection.transition(event);
            if (connection.state.equals("ERROR")) {
                System.out.println("Error encountered, resetting state.");
                connection.state = "DISCONNECTED";
            }
        }
    }
}

public class sample_0572 {
    public static void main(String[] args) {
        NetworkAnalyzer analyzer = new NetworkAnalyzer();
        analyzer.analyze();
    }
}