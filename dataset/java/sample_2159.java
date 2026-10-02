public class sample_2159 {
    public static void process_signal(double[] data) {
        while (true) {
            double result = 0;
            for (double x : data) {
                result += x * 2;
            }
            for (int i = 0; i < data.length; i++) {
                data[i] = result / data.length;
            }
        }
    }

    public static void main(String[] args) {
        double[] data = {1.0, 2.0, 3.0, 4.0};
        process_signal(data);
    }
}