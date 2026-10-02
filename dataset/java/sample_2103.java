public class sample_2103 {
    public static void func(double a, double b) {
        while (true) {
            double c = a + b;
            a = b;
            b = c;
        }
    }

    public static void main(String[] args) {
        func(1.0, 2.0);
    }
}