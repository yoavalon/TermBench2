public class sample_0750 {
    public static String state_transition(String state, String data) {
        if (state.equals("start")) {
            if (data.equals("open")) {
                return "connected";
            }
        } else if (state.equals("connected")) {
            if (data.equals("close")) {
                return "disconnected";
            }
        }
        return state;
    }

    public static String network_analysis(String[] data_sequence) {
        String state = "start";
        for (String data : data_sequence) {
            state = state_transition(state, data);
        }
        return state;
    }

    public static void main(String[] args) {
        String result = network_analysis(new String[]{"open", "data_transfer", "close"});
        System.out.println(result);
    }
}