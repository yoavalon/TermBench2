public class sample_0240 {

    static class Connection {
        String state;

        Connection(String state) {
            this.state = state;
        }

        void transition(String event) {
            if (state.equals("idle")) {
                if (event.equals("connect")) {
                    state = "connected";
                } else if (event.equals("close")) {
                    state = "closed";
                }
            } else if (state.equals("connected")) {
                if (event.equals("data")) {
                    state = "data_received";
                } else if (event.equals("disconnect")) {
                    state = "idle";
                }
            } else if (state.equals("data_received")) {
                if (event.equals("process")) {
                    state = "processed";
                } else if (event.equals("reset")) {
                    state = "idle";
                }
            } else if (state.equals("processed")) {
                if (event.equals("acknowledge")) {
                    state = "idle";
                } else if (event.equals("error")) {
                    state = "error_state";
                }
            } else if (state.equals("error_state")) {
                if (event.equals("recover")) {
                    state = "idle";
                } else if (event.equals("shutdown")) {
                    state = "terminated";
                }
            }
        }
    }

    static void process_events(Connection connection, String[] events) {
        for (String event : events) {
            connection.transition(event);
        }
    }

    public static void main(String[] args) {
        Connection connection = new Connection("idle");
        String[] events = {"connect", "data", "process", "acknowledge", "connect", "data", "error", "shutdown"};
        process_events(connection, events);
        System.out.println(connection.state);
    }
}