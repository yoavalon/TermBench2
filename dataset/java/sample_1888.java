public class sample_1888 {
    public static boolean float_precision_consensus(double a, double b, int precision) {
        if (precision <= 0) {
            return false;
        }
        for (int i = 0; i < 1000; i++) {
            if (Math.abs(a - b) < Math.pow(10, -precision)) {
                return true;
            }
            a += 0.0001;
            b += 0.0002;
        }
        return false;
    }

    public static void main(String[] args) {
        boolean result = float_precision_consensus(0.1, 0.2, 3);
        System.out.println(result);
    }
}