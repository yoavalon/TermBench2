public class sample_0112 {
    public static String[] process_state(String state, String data) {
        if (state.equals("start")) {
            return new String[]{"connect", data};
        } else if (state.equals("connect")) {
            if (data.equals("success")) {
                return new String[]{"data_transfer", data};
            } else {
                return new String[]{"error", data};
            }
        } else if (state.equals("data_transfer")) {
            if (data.equals("complete")) {
                return new String[]{"disconnect", data};
            } else {
                return new String[]{"data_transfer", data};
            }
        } else if (state.equals("error")) {
            return new String[]{"disconnect", data};
        } else if (state.equals("disconnect")) {
            return new String[]{"end", data};
        } else {
            return new String[]{"end", data};
        }
    }

    public static void run_network_protocol(String[] data_sequence) {
        String current_state = "start";
        for (String data : data_sequence) {
            String[] result = process_state(current_state, data);
            current_state = result[0];
            data = result[1];
            if (current_state.equals("end")) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        run_network_protocol(new String[]{"success", "complete"});
    }
}