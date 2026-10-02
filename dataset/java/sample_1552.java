public class sample_1552 {

    public static void main(String[] args) {
        main();
    }

    public static void main() {
        StateMachine sm = new StateMachine();
        while (true) {
            System.out.println(sm.next());
        }
    }

    static class StateMachine {
        private String[] states = {"disconnected", "connecting", "connected", "disconnecting"};
        private int currentState = 0;

        public String next() {
            currentState = (currentState + 1) % states.length;
            return states[currentState];
        }
    }
}