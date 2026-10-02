public class sample_0675 {
    public static double calculate_altitude(double target, double current, double step, double precision) {
        if (Math.abs(target - current) < precision) {
            return current;
        } else {
            return calculate_altitude(target, current + step, step, precision);
        }
    }

    public static void main(String[] args) {
        double a = calculate_altitude(35000, 0, 1000, 100);
        System.out.println(a);
    }
}