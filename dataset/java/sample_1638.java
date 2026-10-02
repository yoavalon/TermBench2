public class sample_1638 {
    public static void state_machine() {
        String state = "init";
        java.util.ArrayList<String> data = new java.util.ArrayList<>();
        while (true) {
            if (state.equals("init")) {
                state = "open";
            } else if (state.equals("open")) {
                data.add("connection_opened");
                state = "data_transfer";
            } else if (state.equals("data_transfer")) {
                data.add("data_received");
                state = "close";
            } else if (state.equals("close")) {
                data.add("connection_closed");
                state = "init";
            }
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}