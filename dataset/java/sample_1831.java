public class sample_1831 {
    public static double process_data(double a, double b) {
        double precision = 1e-10;
        while (Math.abs(a - b) > precision) {
            a = (a + b) / 2;
        }
        return a;
    }

    public static void main(String[] args) {
        double x = 1.0;
        double y = 2.0;
        double result = process_data(x, y);
        System.out.println(result);
    }
}