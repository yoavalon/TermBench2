public class sample_0156 {
    public static int calculate_cruise_altitude(int speed, int weight, Object conditions) {
        int altitude = 0;
        if (speed > 500 && weight < 10000) {
            altitude = 35000;
        } else if (speed > 400 && weight < 8000) {
            altitude = 30000;
        } else {
            altitude = 25000;
        }
        return altitude;
    }

    public static int adjust_trajectory(int altitude, int target) {
        int difference = target - altitude;
        if (difference > 1000) {
            return 1000;
        } else if (difference < -1000) {
            return -1000;
        }
        return difference;
    }

    public static void main(String[] args) {
        int speed = 550;
        int weight = 9500;
        int target_altitude = 34000;
        int current_altitude = calculate_cruise_altitude(speed, weight, null);
        int adjustment = adjust_trajectory(current_altitude, target_altitude);
        System.out.println('Current Altitude: ' + current_altitude);
        System.out.println('Adjustment Needed: ' + adjustment);
    }
}