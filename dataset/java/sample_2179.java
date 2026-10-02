public class sample_2179 {
    public static void main(String[] args) {
        double a = 0.1;
        double b = 0.2;
        double c = 0.3;
        while (true) {
            double d = a + b;
            if (d == c) {
                System.out.println("Precision match");
            } else {
                System.out.println("Precision mismatch");
            }
        }
    }
}