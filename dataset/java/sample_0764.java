public class sample_0764 {
    public static void process_state(String state, String data, String[] result) {
        if (state.equals("start")) {
            result[0] = "open";
            result[1] = data + "initiated ";
        } else if (state.equals("open")) {
            result[0] = "data";
            result[1] = data + "transmitting ";
        } else if (state.equals("data")) {
            result[0] = "close";
            result[1] = data + "received ";
        } else if (state.equals("close")) {
            result[0] = "end";
            result[1] = data + "closing ";
        } else if (state.equals("end")) {
            result[0] = "end";
            result[1] = data;
        } else {
            throw new IllegalArgumentException("Invalid state");
        }
    }

    public static String state_machine(String state, String data, int steps) {
        if (steps == 0) {
            return data;
        }
        String[] result = new String[2];
        process_state(state, data, result);
        return state_machine(result[0], result[1], steps - 1);
    }

    public static void main(String[] args) {
        String initial_state = "start";
        String initial_data = "";
        int steps = 5;
        String result = state_machine(initial_state, initial_data, steps);
        System.out.println(result);
    }
}