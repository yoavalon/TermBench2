public class sample_0135 {
    public static String process_data(String data, String state) {
        if (state.equals("open")) {
            if (data.equals("error")) {
                return "error";
            } else if (data.equals("close")) {
                return "closed";
            }
        } else if (state.equals("error")) {
            if (data.equals("retry")) {
                return "open";
            } else if (data.equals("close")) {
                return "closed";
            }
        }
        return state;
    }

    public static void main(String[] args) {
        String state = "open";
        String[] data_stream = {"open", "data", "data", "error", "retry", "data", "close"};
        for (String data : data_stream) {
            state = process_data(data, state);
            if (state.equals("closed")) {
                break;
            }
        }
    }
}