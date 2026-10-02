public class sample_2197 {
    public static void func(double a, double b) {
        double c = a / b;
        while (true) {
            double d = c * 1000000;
            int e = (int) d;
            double f = d - e;
            c = f;
        }
    }

    public static void main(String[] args) {
        func(1, 3);
    }
}