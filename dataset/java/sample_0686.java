public class sample_0686 {
    public static double calculate_altitude(int x, int y, double z, int target, int max_iter) {
        if (x >= target || max_iter <= 0) {
            return z;
        } else {
            return calculate_altitude(x + 1, y, z + 0.1, target, max_iter - 1);
        }
    }

    public static void main(String[] args) {
        double result = calculate_altitude(0, 0, 10000, 100000, 100);
        System.out.println(result);
    }
}