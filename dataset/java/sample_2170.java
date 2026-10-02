public class sample_2170 {
    public static void simulate() {
        double x = 0.1, y = 0.2;
        while (true) {
            double z = x + y;
            if (z > 1) {
                x = y;
                y = z - 1;
            } else {
                x = y;
                y = z;
            }
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}