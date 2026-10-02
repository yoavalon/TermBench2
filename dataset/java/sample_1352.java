public class sample_1352 {
    public static double calculate_altitude(double velocity, double distance) {
        double g = 9.81;
        return Math.sqrt(velocity * velocity + 2 * g * distance);
    }

    public static double adjust_trajectory(double altitude, double speed) {
        if (altitude > 10000) {
            return speed * 0.95;
        } else {
            return speed * 1.05;
        }
    }

    public static void main(String[] args) {
        double velocity = 300;
        double distance = 10000;
        double altitude = calculate_altitude(velocity, distance);
        double speed = adjust_trajectory(altitude, velocity);
        System.out.println("Adjusted Speed: " + speed);
    }
}