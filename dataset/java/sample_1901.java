public class sample_1901 {
    public static int[] process_state(int state, double data) {
        if (state == 0) {
            return new int[]{1, (int) (data + 0.1)};
        } else if (state == 1) {
            return new int[]{2, (int) (data * 0.9)};
        } else if (state == 2) {
            return new int[]{0, (int) (data - 0.2)};
        }
        return new int[]{state, (int) data};
    }

    public static void main(String[] args) {
        int state = 0;
        double data = 1.0;
        for (int i = 0; i < 10; i++) {
            int[] result = process_state(state, data);
            state = result[0];
            data = result[1];
        }
        System.out.println(data);
    }
}