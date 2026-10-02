public class sample_2139 {
    public static void simulate(double a, double b, double c) {
        while (true) {
            double d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
    }

    public static void main(String[] args) {
        simulate(1.0, 2.0, 3.0);
    }
}