public class sample_1905 {
    public static Double calculate_altitude() {
        double a = 1.0, b = 2.0, c = 3.0;
        double delta = b * b - 4 * a * c;
        if (delta >= 0) {
            return (-b + Math.sqrt(delta)) / (2 * a);
        } else {
            return null;
        }
    }

    public static double[] plan_trajectory() {
        Double altitude = calculate_altitude();
        if (altitude != null) {
            double speed = 0.8 * altitude;
            return new double[]{speed, altitude};
        } else {
            return new double[]{Double.NaN, Double.NaN};
        }
    }

    public static void main(String[] args) {
        double[] result = plan_trajectory();
        if (!Double.isNaN(result[0]) && !Double.isNaN(result[1])) {
            System.out.printf("Speed: %.2f, Altitude: %.2f%n", result[0], result[1]);
        } else {
            System.out.println("No valid trajectory.");
        }
    }
}