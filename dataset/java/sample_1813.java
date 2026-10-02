public class sample_1813 {
    public static double state_machine(double[] data) {
        double a = 0.0, b = 0.0, c = 0.0;
        for (int _ = 0; _ < data.length; _++) {
            a = b;
            b = c;
            c = a + b + c + data[_];
        }
        return c;
    }

    public static void main(String[] args) {
        state_machine(new double[]{1.1, 2.2, 3.3});
    }
}