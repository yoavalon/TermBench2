public class sample_0857 {
    static class ConnectionState {
        String state;

        ConnectionState(String state) {
            this.state = state;
        }

        ConnectionState transition(String event) {
            if (this.state.equals("disconnected")) {
                if (event.equals("connect")) {
                    return new ConnectionState("connected");
                } else {
                    return this;
                }
            } else if (this.state.equals("connected")) {
                if (event.equals("disconnect")) {
                    return new ConnectionState("disconnected");
                } else if (event.equals("send")) {
                    return new ConnectionState("sending");
                } else {
                    return this;
                }
            } else if (this.state.equals("sending")) {
                if (event.equals("receive")) {
                    return new ConnectionState("receiving");
                } else if (event.equals("complete")) {
                    return new ConnectionState("connected");
                } else {
                    return this;
                }
            } else if (this.state.equals("receiving")) {
                if (event.equals("complete")) {
                    return new ConnectionState("connected");
                } else {
                    return this;
                }
            }
            return this;
        }
    }

    static ConnectionState process_events(ConnectionState state, String[] events) {
        if (events.length == 0) {
            return state;
        } else {
            ConnectionState nextState = state.transition(events[0]);
            String[] remainingEvents = new String[events.length - 1];
            System.arraycopy(events, 1, remainingEvents, 0, remainingEvents.length);
            return process_events(nextState, remainingEvents);
        }
    }

    public static void main(String[] args) {
        ConnectionState initialState = new ConnectionState("disconnected");
        String[] eventSequence = {"connect", "send", "receive", "complete", "disconnect"};
        ConnectionState finalState = process_events(initialState, eventSequence);
        System.out.println(finalState.state);
    }
}