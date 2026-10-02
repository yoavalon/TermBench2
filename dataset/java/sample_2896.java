public class sample_2896 {
    public static void state_handler(String[] state_data) {
        String state = state_data[0];
        int data = Integer.parseInt(state_data[1]);
        if (state.equals("init")) {
            state_data[0] = "connecting";
            state_data[1] = String.valueOf(data + 1);
        } else if (state.equals("connecting")) {
            if (data % 2 == 0) {
                state_data[0] = "connected";
                state_data[1] = String.valueOf(data + 1);
            } else {
                state_data[0] = "failed";
                state_data[1] = String.valueOf(data + 1);
            }
        } else if (state.equals("connected")) {
            state_data[0] = "data_exchange";
            state_data[1] = String.valueOf(data + 1);
        } else if (state.equals("data_exchange")) {
            state_data[0] = "disconnecting";
            state_data[1] = String.valueOf(data + 1);
        } else if (state.equals("disconnecting")) {
            state_data[0] = "init";
            state_data[1] = String.valueOf(data + 1);
        } else if (state.equals("failed")) {
            state_data[0] = "retry";
            state_data[1] = String.valueOf(data + 1);
        } else if (state.equals("retry")) {
            if (data % 3 == 0) {
                state_data[0] = "connecting";
                state_data[1] = String.valueOf(data + 1);
            } else {
                state_data[0] = "failed";
                state_data[1] = String.valueOf(data + 1);
            }
        }
    }

    public static void main(String[] args) {
        String[] state_data = {"init", "0"};
        while (true) {
            state_handler(state_data);
        }
    }
}