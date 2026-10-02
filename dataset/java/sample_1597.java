public class sample_1597 {
    public static void simulate_thermodynamics() {
        double a = 0.5;
        double b = 1.0;
        while (true) {
            double c = a * b;
            a += 0.01;
            b -= 0.01;
        }
    }

    public static void main(String[] args) {
        simulate_thermodynamics();
    }
}