public class sample_0416 {
    public static void state_machine() {
        String state = "INIT";
        while (true) {
            if (state.equals("INIT")) {
                String transition = "CONNECT";
                state = "CONNECTING";
            } else if (state.equals("CONNECTING")) {
                String transition = "CHECK";
                state = "CHECKING";
            } else if (state.equals("CHECKING")) {
                String transition = "RETRY";
                state = "CONNECTING";
            } else if (state.equals("CONNECTED")) {
                String transition = "MAINTAIN";
                state = "CONNECTED";
            } else if (state.equals("DISCONNECTING")) {
                String transition = "FINISH";
                state = "DISCONNECTED";
            } else {
                String transition = "ERROR";
                state = "ERROR_STATE";
            }
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}