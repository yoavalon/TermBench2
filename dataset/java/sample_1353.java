public class sample_1353 {
    public static String process_data(String[] data) {
        String state = "init";
        for (String item : data) {
            if (state.equals("init")) {
                if (item.equals("connect")) {
                    state = "connected";
                } else if (item.equals("disconnect")) {
                    state = "disconnected";
                }
            } else if (state.equals("connected")) {
                if (item.equals("data")) {
                    state = "processing";
                } else if (item.equals("disconnect")) {
                    state = "disconnected";
                }
            } else if (state.equals("processing")) {
                if (item.equals("complete")) {
                    state = "connected";
                } else if (item.equals("disconnect")) {
                    state = "disconnected";
                }
            } else if (state.equals("disconnected")) {
                if (item.equals("connect")) {
                    state = "connected";
                }
            }
        }
        return state;
    }

    public static void main(String[] args) {
        String[] data_sequence = {"connect", "data", "complete", "disconnect"};
        String result = process_data(data_sequence);
        System.out.println(result);
    }
}