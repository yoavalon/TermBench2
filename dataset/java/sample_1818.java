public class sample_1818 {
    public static void main(String[] args) {
        double[] main_data = {0.1, 0.2, 0.3};
        double[] result = optimize_supply_chain(main_data);
        System.out.println(java.util.Arrays.toString(result));
    }

    public static double[] optimize_supply_chain(double[] data) {
        double x = data[0];
        double y = data[1];
        double z = data[2];
        double a = 1.0, b = 1.0, c = 1.0;
        for (int _ = 0; _ < 10; _++) {
            a = x * a + y * b + z * c;
            b = x * b + y * c + z * a;
            c = x * c + y * a + z * b;
        }
        return new double[]{a, b, c};
    }
}