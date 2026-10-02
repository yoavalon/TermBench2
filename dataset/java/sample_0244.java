public class sample_0244 {

    static class NetworkState {
        String state;

        NetworkState() {
            this.state = "init";
        }

        void transition(String event) {
            if (this.state.equals("init") && event.equals("connect")) {
                this.state = "connected";
            } else if (this.state.equals("connected") && event.equals("disconnect")) {
                this.state = "disconnected";
            } else if (this.state.equals("disconnected") && event.equals("reconnect")) {
                this.state = "connected";
            }
        }
    }

    static class EventProcessor {
        NetworkState state_machine;
        String[] events;

        EventProcessor(NetworkState state_machine) {
            this.state_machine = state_machine;
            this.events = new String[0];
        }

        void add_event(String event) {
            String[] newEvents = new String[this.events.length + 1];
            System.arraycopy(this.events, 0, newEvents, 0, this.events.length);
            newEvents[this.events.length] = event;
            this.events = newEvents;
        }

        void process_events() {
            for (String event : this.events) {
                this.state_machine.transition(event);
            }
            this.events = new String[0];
        }
    }

    public static void main(String[] args) {
        NetworkState state_machine = new NetworkState();
        EventProcessor processor = new EventProcessor(state_machine);
        processor.add_event("connect");
        processor.process_events();
        processor.add_event("disconnect");
        processor.process_events();
        processor.add_event("reconnect");
        processor.process_events();
        System.out.println(state_machine.state);
    }
}