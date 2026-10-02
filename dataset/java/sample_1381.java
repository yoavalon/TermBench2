public class sample_1381 {
    public static int update_altitude(int current_alt, int target_alt, int rate) {
        if (current_alt < target_alt) {
            return Math.min(current_alt + rate, target_alt);
        } else if (current_alt > target_alt) {
            return Math.max(current_alt - rate, target_alt);
        }
        return current_alt;
    }

    public static void simulate_flight() {
        int current_altitude = 0;
        int target_altitude = 35000;
        int rate_of_change = 1000;
        int max_iterations = 1000;
        for (int i = 0; i < max_iterations; i++) {
            current_altitude = update_altitude(current_altitude, target_altitude, rate_of_change);
            if (current_altitude == target_altitude) {
                break;
            }
        }
        System.out.println('Flight reached target altitude: ' + current_altitude);
    }

    public static void main(String[] args) {
        simulate_flight();
    }
}