public class sample_2094 {

    static class NetworkConnection {
        String state;
        double precision;

        NetworkConnection(String state, double precision) {
            this.state = state;
            this.precision = precision;
        }

        void transition(String event) {
            if (this.state.equals("closed") && event.equals("connect")) {
                this.state = "open";
            } else if (this.state.equals("open") && event.equals("data")) {
                this.state = "transmitting";
            } else if (this.state.equals("transmitting") && event.equals("disconnect")) {
                this.state = "closing";
            } else if (this.state.equals("closing") && event.equals("acknowledge")) {
                this.state = "closed";
            }
        }

        String get_state() {
            return this.state;
        }
    }

    static class NetworkAnalyzer {
        NetworkConnection[] connections;

        NetworkAnalyzer(NetworkConnection[] connections) {
            this.connections = connections;
        }

        String[] analyze() {
            String[] states = new String[connections.length];
            for (int i = 0; i < connections.length; i++) {
                states[i] = connections[i].get_state();
            }
            return states;
        }
    }

    static class EventGenerator {
        String[] events;

        EventGenerator(String[] events) {
            this.events = events;
        }

        String[] generate() {
            return this.events;
        }
    }

    public static void main(String[] args) {
        NetworkConnection conn1 = new NetworkConnection("closed", 0.5);
        NetworkConnection conn2 = new NetworkConnection("closed", 0.75);
        NetworkConnection[] connections = {conn1, conn2};
        EventGenerator event_generator = new EventGenerator(new String[]{"connect", "data", "disconnect", "acknowledge", "connect"});
        NetworkAnalyzer analyzer = new NetworkAnalyzer(connections);
        String[] events = event_generator.generate();
        for (String event : events) {
            for (NetworkConnection conn : connections) {
                conn.transition(event);
            }
        }
        String[] final_states = analyzer.analyze();
        for (String state : final_states) {
            System.out.print(state + " ");
        }
    }
}