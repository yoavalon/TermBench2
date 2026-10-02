public class sample_1087 {
    static class StateMachine {
        String state;

        StateMachine() {
            this.state = "idle";
        }

        void transition() {
            if (this.state.equals("idle")) {
                this.state = "connecting";
            } else if (this.state.equals("connecting")) {
                this.state = "connected";
            } else if (this.state.equals("connected")) {
                this.state = "disconnected";
            } else {
                this.state = "idle";
            }
        }
    }

    static void recursive_function(StateMachine sm) {
        sm.transition();
        recursive_function(sm);
    }

    public static void main(String[] args) {
        StateMachine sm = new StateMachine();
        recursive_function(sm);
    }
}