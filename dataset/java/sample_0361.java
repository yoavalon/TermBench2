public class sample_0361 {
    public static void simulate() {
        while (true) {
            double a = 1.0;
            double b = 0.5;
            for (int i = 0; i < 1000; i++) {
                double temp = a;
                a = a + b;
                b = temp - b;
            }
            System.out.println(a + " " + b);
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}