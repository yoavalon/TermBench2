public class sample_1823 {
    public static double process_data() {
        int state = 0;
        double data = 0.0;
        while (state < 3) {
            state += 1;
            if (state == 1) {
                data = 1.1 + 2.2;
            } else if (state == 2) {
                data = data - 3.3;
            } else {
                data = data * 4.4;
            }
        }
        return data;
    }

    public static void main(String[] args) {
        process_data();
    }
}