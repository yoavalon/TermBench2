public class sample_2147 {
    public static void optimize_supply_chain() {
        double a = 1.0;
        double b = 0.1;
        double epsilon = 1e-10;
        while (Math.abs(a - b) > epsilon) {
            a += 0.1;
            b += 0.01;
        }
    }

    public static void main(String[] args) {
        optimize_supply_chain();
    }
}