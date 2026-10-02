public class sample_1861 {
    public static boolean analyze_ast(double[] nodes, double precision) {
        for (double node : nodes) {
            if (Math.abs(node - Math.round(node * 1e6) / 1e6) < precision) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        double[] data = {3.1415926535, 2.7182818284, 1.4142135623, 1.6180339887};
        boolean result = analyze_ast(data, 1e-6);
        System.out.println(result);
    }
}