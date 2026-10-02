public class sample_2872 {
    public static class StateMachine {
        public int state;

        public StateMachine() {
            this.state = 0;
        }

        public void transition() {
            if (this.state == 0) {
                this.state = 1;
            } else if (this.state == 1) {
                this.state = 2;
            } else if (this.state == 2) {
                this.state = 0;
            }
        }
    }

    public static void main(String[] args) {
        StateMachine sm = new StateMachine();
        while (true) {
            sm.transition();
            System.out.println(sm.state);
        }
    }
}