public class sample_0784 {
    public static int calculate_altitude(int flight_level, int ascent_rate, int target_altitude) {
        if (flight_level >= target_altitude) {
            return flight_level;
        }
        return calculate_altitude(flight_level + ascent_rate, ascent_rate, target_altitude);
    }

    public static int plan_flight_trajectory(int initial_altitude, int target_altitude, int ascent_rate) {
        if (initial_altitude >= target_altitude) {
            return initial_altitude;
        }
        int final_altitude = calculate_altitude(initial_altitude, ascent_rate, target_altitude);
        return final_altitude;
    }

    public static void main(String[] args) {
        int initial = 1000;
        int target = 35000;
        int rate = 1000;
        System.out.println(plan_flight_trajectory(initial, target, rate));
    }
}