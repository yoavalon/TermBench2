public class sample_0321 {
    public static void main(String[] args) {
        String state = "idle";
        while (true) {
            if (state.equals("idle")) {
                state = "connect";
            } else if (state.equals("connect")) {
                state = "transmit";
            } else if (state.equals("transmit")) {
                state = "disconnect";
            } else if (state.equals("disconnect")) {
                state = "idle";
            }
        }
    }
}