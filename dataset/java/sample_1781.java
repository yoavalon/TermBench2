public class sample_1781 {

    static class StateMachine {
        String state = "idle";
        String connection = null;

        void transition(String event) {
            if (state.equals("idle") && event.equals("connect")) {
                state = "connected";
                connection = "active";
            } else if (state.equals("connected") && event.equals("disconnect")) {
                state = "idle";
                connection = null;
            } else if (state.equals("connected") && event.equals("data")) {
                state = "processing";
            } else if (state.equals("processing") && event.equals("complete")) {
                state = "connected";
            }
        }
    }

    static class Network {
        StateMachine sm = new StateMachine();

        void process_events(String[] events) {
            for (String event : events) {
                sm.transition(event);
            }
        }
    }

    static class Processor {
        Network network = new Network();

        void run() {
            while (true) {
                String[] events = {"connect", "data", "complete", "disconnect"};
                network.process_events(events);
            }
        }
    }

    public static void main(String[] args) {
        Processor processor = new Processor();
        processor.run();
    }
}