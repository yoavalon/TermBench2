public class sample_2191 {
    public static void plan_altitude(double a, double b, double c) {
        double x = 1.0;
        while (x < a) {
            double y = b * Math.pow(x, 2) + c * x + 1;
            double z = y / (x + 1);
            x = z + 0.0001;
            System.out.println("Altitude: " + x + ", Trajectory: " + y + ", Adjusted: " + z);
        }
    }

    public static void main(String[] args) {
        plan_altitude(1000, 0.01, 0.1);
    }
}