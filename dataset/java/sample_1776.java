import java.util.ArrayList;
import java.util.List;

public class sample_1776 {
    public static List<Integer> calculate_altitude_profile(int cruise_altitude, int max_altitude, int step) {
        List<Integer> altitude_list = new ArrayList<>();
        int current_altitude = 0;
        while (current_altitude < max_altitude) {
            altitude_list.add(current_altitude);
            if (current_altitude < cruise_altitude) {
                current_altitude += step;
            } else {
                current_altitude -= step;
            }
        }
        return altitude_list;
    }

    public static List<Integer> adjust_flight_path(List<Integer> altitude_profile, int wind_factor) {
        List<Integer> adjusted_profile = new ArrayList<>();
        for (int altitude : altitude_profile) {
            int adjusted_altitude = altitude + wind_factor;
            adjusted_profile.add(adjusted_altitude);
        }
        return adjusted_profile;
    }

    public static List<Integer> optimize_trajectory(List<Integer> trajectory, int target_altitude) {
        List<Integer> optimized_trajectory = new ArrayList<>();
        for (int altitude : trajectory) {
            if (altitude < target_altitude) {
                optimized_trajectory.add(target_altitude);
            } else {
                optimized_trajectory.add(altitude);
            }
        }
        return optimized_trajectory;
    }

    public static void main(String[] args) {
        int cruise_altitude = 30000;
        int max_altitude = 40000;
        int step = 1000;
        int wind_factor = 500;
        int target_altitude = 35000;
        List<Integer> altitude_profile = calculate_altitude_profile(cruise_altitude, max_altitude, step);
        List<Integer> adjusted_profile = adjust_flight_path(altitude_profile, wind_factor);
        List<Integer> optimized_trajectory = optimize_trajectory(adjusted_profile, target_altitude);
        System.out.println(optimized_trajectory);
    }
}