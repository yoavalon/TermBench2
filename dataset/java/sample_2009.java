public class sample_2009 {

    static class ConnectionState {
        String state;
        java.util.ArrayList<String> data_buffer;

        ConnectionState() {
            this.state = "DISCONNECTED";
            this.data_buffer = new java.util.ArrayList<>();
        }

        String transition(String event) {
            if (this.state.equals("DISCONNECTED") && event.equals("CONNECT")) {
                this.state = "CONNECTED";
            } else if (this.state.equals("CONNECTED") && event.equals("SEND")) {
                this.state = "SENDING";
            } else if (this.state.equals("SENDING") && event.equals("ACKNOWLEDGE")) {
                this.state = "ACKNOWLEDGED";
            } else if (this.state.equals("ACKNOWLEDGED") && event.equals("DISCONNECT")) {
                this.state = "DISCONNECTED";
            } else if (this.state.equals("CONNECTED") && event.equals("DATA")) {
                this.data_buffer.add(event);
            } else if (this.state.equals("SENDING") && event.equals("REJECT")) {
                this.state = "REJECTED";
            } else if (this.state.equals("REJECTED") && event.equals("RETRY")) {
                this.state = "SENDING";
            }
            return this.state;
        }
    }

    static class NetworkHandler {
        ConnectionState connection;

        NetworkHandler() {
            this.connection = new ConnectionState();
        }

        String process_event(String event) {
            String new_state = this.connection.transition(event);
            return new_state;
        }
    }

    static class EventSimulator {
        String[] events;

        EventSimulator() {
            this.events = new String[]{"CONNECT", "DATA", "SEND", "ACKNOWLEDGE", "DISCONNECT"};
        }

        String[] generate_events() {
            return this.events;
        }
    }

    public static void main(String[] args) {
        NetworkHandler handler = new NetworkHandler();
        EventSimulator simulator = new EventSimulator();
        for (String event : simulator.generate_events()) {
            String state = handler.process_event(event);
            System.out.println("Event: " + event + ", New State: " + state);
        }
    }
}