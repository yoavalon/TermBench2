public class sample_2791 {
    public static void generate_flight_trajectory() {
        double x = 0;
        double y = 0;
        double v = 100;
        double g = 9.81;
        while (true) {
            y = v * x - 0.5 * g * x * x;
            System.out.println("Time: " + x + ", Altitude: " + y);
            x += 1;
        }
    }

    public static void main(String[] args) {
        generate_flight_trajectory();
    }
}