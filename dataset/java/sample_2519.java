import java.util.ArrayList;
import java.util.List;

public class sample_2519 {
    public static int calculate_altitude(int time) {
        if (time < 10) {
            return 5000;
        } else if (time < 20) {
            return 10000;
        } else {
            return 15000;
        }
    }

    public static List<Integer> simulate_flight(int duration) {
        List<Integer> altitudes = new ArrayList<>();
        for (int t = 1; t <= duration; t++) {
            altitudes.add(calculate_altitude(t));
        }
        return altitudes;
    }

    public static void main(String[] args) {
        int flight_duration = 30;
        List<Integer> trajectory = simulate_flight(flight_duration);
        for (int time = 1; time <= trajectory.size(); time++) {
            int altitude = trajectory.get(time - 1);
            System.out.println("Time: " + time + ", Altitude: " + altitude);
        }
    }
}