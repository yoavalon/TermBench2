public class sample_2000 {
    public static int process_data(int state, double data) {
        if (state == 0) {
            return data > 0.5 ? 1 : 2;
        } else if (state == 1) {
            return data < 0.3 ? 0 : 2;
        } else if (state == 2) {
            return 3;
        }
        return state;
    }

    public static void main(String[] args) {
        int state = 0;
        double[] data_points = {0.6, 0.2, 0.4, 0.7};
        for (double data : data_points) {
            state = process_data(state, data);
            if (state == 3) {
                break;
            }
        }
    }
}