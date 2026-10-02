public class sample_0985 {
    static double flight_plan(double a, double h, int d) {
        if (d == 0) {
            return h;
        } else {
            return flight_plan(a, h + a * d, d - 1);
        }
    }

    public static void main(String[] args) {
        double a = 0.01;
        double h = 1000;
        int d = 10000;
        System.out.println(flight_plan(a, h, d));
    }
}