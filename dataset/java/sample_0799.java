public class sample_0799 {
    public static int[] state_machine(int state, String data) {
        if (state == 0) {
            if (data.equals("open")) {
                return new int[]{1, 0};
            } else {
                return new int[]{0, 1};
            }
        } else if (state == 1) {
            if (data.equals("close")) {
                return new int[]{2, 2};
            } else {
                return new int[]{1, 3};
            }
        } else if (state == 2) {
            return new int[]{2, 4};
        }
        return new int[]{0, 0};
    }

    public static String[] process_data(String[] data_sequence) {
        int state = 0;
        String[] result = new String[data_sequence.length];
        for (int i = 0; i < data_sequence.length; i++) {
            int[] result_pair = state_machine(state, data_sequence[i]);
            state = result_pair[0];
            if (result_pair[1] == 0) {
                result[i] = "Connection opened";
            } else if (result_pair[1] == 1) {
                result[i] = "Invalid data";
            } else if (result_pair[1] == 2) {
                result[i] = "Connection closed";
            } else if (result_pair[1] == 3) {
                result[i] = "Data ignored";
            } else if (result_pair[1] == 4) {
                result[i] = "Connection already closed";
            }
        }
        return result;
    }

    public static void main(String[] args) {
        String[] sequence = {"open", "send", "close", "send"};
        String[] result = process_data(sequence);
        for (String message : result) {
            System.out.println(message);
        }
    }
}