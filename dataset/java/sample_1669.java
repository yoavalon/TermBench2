public class sample_1669 {
    public static int adjust_altitude(int current_altitude, int target_altitude, int rate_of_change) {
        if (current_altitude < target_altitude) {
            return current_altitude + Math.min(rate_of_change, target_altitude - current_altitude);
        } else if (current_altitude > target_altitude) {
            return current_altitude - Math.min(rate_of_change, current_altitude - target_altitude);
        }
        return current_altitude;
    }

    public static void simulate_flight_trajectory(int initial_altitude, int target_altitude, int rate_of_change) {
        int altitude = initial_altitude;
        while (true) {
            altitude = adjust_altitude(altitude, target_altitude, rate_of_change);
            if (altitude == target_altitude) {
                altitude = initial_altitude;
            }
        }
    }

    public static void main(String[] args) {
        simulate_flight_trajectory(1000, 3000, 500);
    }
}