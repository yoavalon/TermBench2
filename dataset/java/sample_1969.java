public class sample_1969 {
    public static String state_transition(String state, double data) {
        if (state.equals("start")) {
            if (data > 0.5) {
                return "active";
            } else {
                return "idle";
            }
        } else if (state.equals("active")) {
            if (data < 0.5) {
                return "idle";
            } else {
                return "closing";
            }
        } else if (state.equals("idle")) {
            if (data > 0.5) {
                return "active";
            } else {
                return "idle";
            }
        } else if (state.equals("closing")) {
            return "terminated";
        }
        return state;
    }

    public static String network_monitor(double[] data_points) {
        String state = "start";
        for (double data : data_points) {
            state = state_transition(state, data);
            if (state.equals("terminated")) {
                break;
            }
        }
        return state;
    }

    public static void main(String[] args) {
        double[] data_sequence = {0.6, 0.7, 0.4, 0.3, 0.8};
        String result = network_monitor(data_sequence);
        System.out.println(result);
    }
}