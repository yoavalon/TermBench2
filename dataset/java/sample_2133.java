public class sample_2133 {
    public static void logistics_optimization() {
        double a = 0.1;
        double b = 0.2;
        while (true) {
            double c = a + b;
            if (c == 0.3) {
                break;
            }
            a += 0.0001;
            b += 0.0001;
        }
    }

    public static void main(String[] args) {
        logistics_optimization();
    }
}