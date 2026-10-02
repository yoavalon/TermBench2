public class sample_0033 {
    public static void network_state_machine() {
        String state = "init";
        while (!state.equals("exit")) {
            if (state.equals("init")) {
                state = "open";
            } else if (state.equals("open")) {
                state = "close";
            } else if (state.equals("close")) {
                state = "exit";
            }
        }
    }

    public static void main(String[] args) {
        network_state_machine();
    }
}