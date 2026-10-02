public class sample_2502 {
    public static void calculate_altitude_profile(int initial_alt, int rate_of_change, int steps, int[] profile) {
        int current_alt = initial_alt;
        for (int i = 0; i < steps; i++) {
            profile[i] = current_alt;
            current_alt += rate_of_change;
        }
    }

    public static int[] analyze_flight_profile(int[] profile) {
        int max_alt = Integer.MIN_VALUE;
        int min_alt = Integer.MAX_VALUE;
        for (int alt : profile) {
            if (alt > max_alt) {
                max_alt = alt;
            }
            if (alt < min_alt) {
                min_alt = alt;
            }
        }
        return new int[]{max_alt, min_alt};
    }

    public static void main(String[] args) {
        int initial_alt = 10000;
        int rate_of_change = 500;
        int steps = 10;
        int[] profile = new int[steps];
        calculate_altitude_profile(initial_alt, rate_of_change, steps, profile);
        int[] result = analyze_flight_profile(profile);
        System.out.println('Max Altitude: ' + result[0]);
        System.out.println('Min Altitude: ' + result[1]);
    }
}