public class sample_1820 {
    public static double ledger_consensus(double a, double b, double precision) {
        while (Math.abs(a - b) > precision) {
            a = (a + b) / 2;
            b = (a + b) / 2;
        }
        return a;
    }

    public static void main(String[] args) {
        double x = 1.0;
        double y = 2.0;
        double p = 0.0001;
        double result = ledger_consensus(x, y, p);
        System.out.println(result);
    }
}