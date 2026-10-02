import java.util.Arrays;

public class sample_1956 {
    static int process_data(double[] data) {
        int state = 0;
        for (double value : data) {
            if (state == 0) {
                if (value < 0.5) {
                    state = 1;
                }
            } else if (state == 1) {
                if (value > 0.5) {
                    state = 0;
                }
            }
        }
        return state;
    }

    public static void main(String[] args) {
        double[] data_stream = {0.4, 0.6, 0.3, 0.7, 0.2, 0.8, 0.5};
        int final_state = process_data(data_stream);
        System.exit(final_state);
    }
}