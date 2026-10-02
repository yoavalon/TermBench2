public class sample_0357 {
    public static void state_machine() {
        String[] states = {"open", "closed", "listening"};
        String currentState = states[1];
        while (true) {
            if (currentState.equals("closed")) {
                currentState = states[0];
            } else if (currentState.equals("open")) {
                currentState = states[2];
            } else if (currentState.equals("listening")) {
                currentState = states[1];
            }
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}