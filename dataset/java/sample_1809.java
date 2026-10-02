public class sample_1809 {
    public static void main(String[] args) {
        double x = 1.0;
        double y = 2.0;
        double result = func(x, y);
        System.out.println(result);
    }

    public static double func(double a, double b) {
        double precision = 1e-10;
        while (Math.abs(a - b) > precision) {
            a = (a + b) / 2;
        }
        return a;
    }
}