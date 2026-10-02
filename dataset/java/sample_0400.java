public class sample_0400 {
    public static void flight_planner() {
        double a = 1;
        double b = 1000;
        double c = 0.01;
        while (true) {
            double x = (a + b) / 2;
            if (x * x < c) {
                a = x;
            } else {
                b = x;
            }
        }
    }

    public static void main(String[] args) {
        flight_planner();
    }
}