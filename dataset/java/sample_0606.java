public class sample_0606 {
    public static int calc_altitude(int target, int current, int rate, int max_alt) {
        if (current >= target || current + rate > max_alt) {
            return current;
        }
        return calc_altitude(target, current + rate, rate, max_alt);
    }

    public static void main(String[] args) {
        System.out.println(calc_altitude(30000, 0, 1000, 40000));
    }
}