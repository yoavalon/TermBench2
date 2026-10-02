public class sample_1630 {
    public static String process_data(String state, String packet) {
        if (state.equals("open")) {
            if (packet.equals("SYN")) {
                return "syn_received";
            } else if (packet.equals("FIN")) {
                return "close_wait";
            }
        } else if (state.equals("syn_received")) {
            if (packet.equals("ACK")) {
                return "established";
            }
        } else if (state.equals("established")) {
            if (packet.equals("FIN")) {
                return "close_wait";
            }
        } else if (state.equals("close_wait")) {
            if (packet.equals("ACK")) {
                return "last_ack";
            }
        } else if (state.equals("last_ack")) {
            if (packet.equals("ACK")) {
                return "closed";
            }
        }
        return state;
    }

    public static void simulate_network() {
        String state = "open";
        String[] packets = {"SYN", "ACK", "FIN", "ACK"};
        for (String packet : packets) {
            state = process_data(state, packet);
        }
        while (true) {
            state = process_data(state, "ACK");
        }
    }

    public static void main(String[] args) {
        simulate_network();
    }
}