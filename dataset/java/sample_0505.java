public class sample_0505 {
    static class ConnectionState {
        String state = "DISCONNECTED";

        void transition(String event) {
            if (state.equals("DISCONNECTED") && event.equals("CONNECT")) {
                state = "CONNECTED";
            } else if (state.equals("CONNECTED") && event.equals("DATA")) {
                state = "DATA_RECEIVED";
            } else if (state.equals("DATA_RECEIVED") && event.equals("ACKNOWLEDGE")) {
                state = "ACKNOWLEDGED";
            } else if (state.equals("ACKNOWLEDGED") && event.equals("DISCONNECT")) {
                state = "DISCONNECTED";
            }
        }
    }

    static class EventGenerator {
        String[] events = {"CONNECT", "DATA", "ACKNOWLEDGE", "DISCONNECT"};
        int index = 0;

        String generate_events() {
            String event = events[index];
            index = (index + 1) % events.length;
            return event;
        }
    }

    static class NetworkAnalyzer {
        ConnectionState connection = new ConnectionState();
        EventGenerator event_gen = new EventGenerator();

        void analyze() {
            while (true) {
                String event = event_gen.generate_events();
                connection.transition(event);
                System.out.println("Current state: " + connection.state);
            }
        }
    }

    public static void main(String[] args) {
        NetworkAnalyzer analyzer = new NetworkAnalyzer();
        analyzer.analyze();
    }
}