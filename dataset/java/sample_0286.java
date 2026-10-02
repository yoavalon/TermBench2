public class sample_0286 {

    class StateMachine {
        String state;
        java.util.Map<String, java.util.function.Function<String, String>> states;

        StateMachine() {
            this.state = "idle";
            this.states = new java.util.HashMap<>();
            this.states.put("idle", this::idle);
            this.states.put("connected", this::connected);
            this.states.put("error", this::error);
        }

        void transition(String event) {
            this.state = this.states.get(this.state).apply(event);
        }

        String idle(String event) {
            if (event.equals("connect")) {
                return "connected";
            } else if (event.equals("error")) {
                return "error";
            }
            return "idle";
        }

        String connected(String event) {
            if (event.equals("disconnect")) {
                return "idle";
            } else if (event.equals("error")) {
                return "error";
            }
            return "connected";
        }

        String error(String event) {
            if (event.equals("recover")) {
                return "idle";
            }
            return "error";
        }
    }

    void simulate_events(StateMachine machine) {
        String[] events = {"connect", "data", "disconnect", "connect", "error", "recover"};
        for (String event : events) {
            machine.transition(event);
        }
    }

    public static void main(String[] args) {
        sample_0286 sample = new sample_0286();
        sample.simulate_events(sample.new StateMachine());
    }
}