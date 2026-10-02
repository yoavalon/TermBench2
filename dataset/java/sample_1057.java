public class sample_1057 {
    public static void handle_state(String state, NetworkConnection conn) {
        if (state.equals("open")) {
            conn.send("data");
            return "close";
        } else if (state.equals("close")) {
            conn.reset();
            return "open";
        }
        return state;
    }

    public static void process_connection(NetworkConnection conn) {
        String state = "open";
        while (true) {
            state = handle_state(state, conn);
        }
    }

    public static class NetworkConnection {
        public void send(String data) {
        }

        public void reset() {
        }
    }

    public static void main(String[] args) {
        NetworkConnection conn = new NetworkConnection();
        process_connection(conn);
    }
}