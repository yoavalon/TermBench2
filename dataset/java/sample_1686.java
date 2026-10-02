public class sample_1686 {
    public static double calculate_altitude(int speed, int distance) {
        double altitude = (double) speed * distance / 1000;
        return altitude;
    }

    public static double adjust_trajectory(double altitude, int target) {
        if (altitude < target) {
            return altitude + 100;
        } else if (altitude > target) {
            return altitude - 100;
        } else {
            return altitude;
        }
    }

    public static void main(String[] args) {
        int speed = 800;
        int distance = 1000;
        int target = 5000;
        while (true) {
            double altitude = calculate_altitude(speed, distance);
            altitude = adjust_trajectory(altitude, target);
            distance += 100;
        }
    }
}