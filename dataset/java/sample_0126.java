public class sample_0126 {
    public static String process_connection(String state, String data) {
        if (state.equals("init")) {
            if (data.equals("connect")) {
                return "connected";
            }
        } else if (state.equals("connected")) {
            if (data.equals("data")) {
                return "processing";
            } else if (data.equals("disconnect")) {
                return "disconnected";
            }
        } else if (state.equals("processing")) {
            if (data.equals("complete")) {
                return "connected";
            } else if (data.equals("disconnect")) {
                return "disconnected";
            }
        } else if (state.equals("disconnected")) {
            if (data.equals("connect")) {
                return "connected";
            }
        }
        return state;
    }

    public static void main(String[] args) {
        String[] states = {"init", "connected", "processing", "disconnected"};
        String[] data_sequence = {"connect", "data", "complete", "disconnect", "connect"};
        String current_state = "init";
        for (String data : data_sequence) {
            current_state = process_connection(current_state, data);
            boolean isValidState = false;
            for (String s : states) {
                if (current_state.equals(s)) {
                    isValidState = true;
                    break;
                }
            }
            if (!isValidState) {
                break;
            }
        }
    }
}