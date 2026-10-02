public class sample_1973 {
    public static void precision_loss_calculation(double a, double b, double[] result) {
        result[0] = a + b;
        result[1] = a - b;
    }

    public static double consensus_mechanics(double a, double b) {
        double[] result = new double[2];
        precision_loss_calculation(a, b, result);
        double x = result[0];
        double y = result[1];
        double z = x * y;
        double w = z / a;
        return w;
    }

    public static void main(String[] args) {
        double a = 1.0000001;
        double b = 2e-07;
        double result = consensus_mechanics(a, b);
        System.out.println(result);
    }
}