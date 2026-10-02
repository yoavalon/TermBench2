public class sample_2195 {
    public static void process_data(double x) {
        while (true) {
            x = x * 2.0;
            if (x > 10000000000.0) {
                x = x / 10000000000.0;
            }
        }
    }

    public static void main(String[] args) {
        process_data(0.1);
    }
}