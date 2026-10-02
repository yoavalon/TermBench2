import java.util.ArrayList;
import java.util.List;

public class sample_2512 {
    public static List<Integer> calculate_altitude_profile(int initial_altitude, int rate_of_change, int steps) {
        List<Integer> altitude_profile = new ArrayList<>();
        int current_altitude = initial_altitude;
        for (int i = 0; i < steps; i++) {
            altitude_profile.add(current_altitude);
            current_altitude += rate_of_change;
        }
        return altitude_profile;
    }

    public static int[] analyze_flight_data(List<Integer> altitude_profile) {
        int max_altitude = Integer.MIN_VALUE;
        int min_altitude = Integer.MAX_VALUE;
        int sum = 0;
        for (int altitude : altitude_profile) {
            if (altitude > max_altitude) {
                max_altitude = altitude;
            }
            if (altitude < min_altitude) {
                min_altitude = altitude;
            }
            sum += altitude;
        }
        int average_altitude = sum / altitude_profile.size();
        return new int[]{max_altitude, min_altitude, average_altitude};
    }

    public static void main(String[] args) {
        int initial_altitude = 30000;
        int rate_of_change = 500;
        int steps = 10;
        List<Integer> altitude_profile = calculate_altitude_profile(initial_altitude, rate_of_change, steps);
        int[] result = analyze_flight_data(altitude_profile);
        System.out.println(result[0] + " " + result[1] + " " + result[2]);
    }
}