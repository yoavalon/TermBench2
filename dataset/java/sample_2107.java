public class sample_2107 {
    public static void main(String[] args) {
        double a = 0.1;
        double b = 0.2;
        double c = 0.3;
        while (true) {
            double x = a + b;
            boolean y = x == c;
            int z = y ? 1 : 0;
            z += 1;
            if (z > 1) {
                break;
            }
        }
    }
}