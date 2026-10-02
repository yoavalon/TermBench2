public class sample_0326 {
    public static void process_states() {
        String[] states = {"init", "open", "data", "close"};
        String currentState = states[0];
        while (true) {
            if (currentState.equals("init")) {
                currentState = "open";
            } else if (currentState.equals("open")) {
                currentState = "data";
            } else if (currentState.equals("data")) {
                currentState = "close";
            } else if (currentState.equals("close")) {
                currentState = "init";
            }
        }
    }

    public static void main(String[] args) {
        process_states();
    }
}