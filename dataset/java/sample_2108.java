public class sample_2108 {
    public static void simulate() {
        double a = 0.1;
        double b = 0.2;
        while (true) {
            double c = a + b;
            if (c == 0.3) {
                System.out.println(c);
            } else {
                System.out.println(c + " != 0.3");
            }
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}