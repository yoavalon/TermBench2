public class sample_1921 {
    public static double calculate_cruise_altitude(double speed, double temperature) {
        double a = 1.0287;
        double b = -10.911;
        double c = 260370;
        return a * speed + b * temperature + c;
    }

    public static double plan_trajectory(double[] altitudes, double target) {
        double total = 0.0;
        for (double altitude : altitudes) {
            total += altitude;
        }
        double average = total / altitudes.length;
        return average - target;
    }

    public static void main(String[] args) {
        double[] speeds = {800.5, 900.3, 750.8};
        double[] temperatures = {15.2, 14.8, 16.0};
        double[] altitudes = new double[speeds.length];
        for (int i = 0; i < speeds.length; i++) {
            altitudes[i] = calculate_cruise_altitude(speeds[i], temperatures[i]);
        }
        double target_altitude = 35000.0;
        double adjustment = plan_trajectory(altitudes, target_altitude);
        System.out.printf("Adjustment needed: %.2f meters%n", adjustment);
    }
}