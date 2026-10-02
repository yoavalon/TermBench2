import java.util.Arrays;

public class sample_1924 {
    public static String[] process_data(int data, String state) {
        if (state.equals("start")) {
            if (data == 1) {
                return new String[]{"connected", "1.0"};
            } else {
                return new String[]{"disconnected", "0.0"};
            }
        } else if (state.equals("connected")) {
            if (data == 0) {
                return new String[]{"disconnected", "0.5"};
            } else {
                return new String[]{"connected", "1.5"};
            }
        } else {
            return new String[]{"error", "-1.0"};
        }
    }

    public static void main(String[] args) {
        String state = "start";
        int[] data_sequence = {1, 0, 1, 0, 1};
        double result = 0.0;
        for (int data : data_sequence) {
            String[] output = process_data(data, state);
            state = output[0];
            result += Double.parseDouble(output[1]);
        }
        System.out.println(result);
    }
}