public class sample_2156 {
    public static void calculate_altitude() {
        double a = 30000.0;
        double b = 0.0001;
        while (true) {
            a += b;
            b /= 2;
        }
    }

    public static void main(String[] args) {
        calculate_altitude();
    }
}