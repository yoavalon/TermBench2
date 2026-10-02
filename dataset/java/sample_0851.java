public class sample_0851 {

    static class Connection {
        String status;

        Connection(String status) {
            this.status = status;
        }

        void change_status(String new_status) {
            this.status = new_status;
        }
    }

    static class StateMachine {
        String current_state;

        StateMachine(String initial_state) {
            this.current_state = initial_state;
        }

        void transition(String event) {
            if (this.current_state.equals("disconnected") && event.equals("connect")) {
                this.current_state = "connected";
            } else if (this.current_state.equals("connected") && event.equals("disconnect")) {
                this.current_state = "disconnected";
            }
        }
    }

    static void process_event(StateMachine state_machine, String event, Connection connection) {
        if (event.equals("connect")) {
            connection.change_status("active");
        } else if (event.equals("disconnect")) {
            connection.change_status("inactive");
        }
        state_machine.transition(event);
    }

    static void simulate_network_activity(StateMachine state_machine, Connection connection, String[] events) {
        if (events.length == 0) {
            return;
        }
        String event = events[0];
        process_event(state_machine, event, connection);
        simulate_network_activity(state_machine, connection, Arrays.copyOfRange(events, 1, events.length));
    }

    public static void main(String[] args) {
        Connection connection = new Connection("inactive");
        StateMachine state_machine = new StateMachine("disconnected");
        String[] events = {"connect", "disconnect", "connect", "disconnect", "connect"};
        simulate_network_activity(state_machine, connection, events);
    }
}