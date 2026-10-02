import java.util.ArrayList;
import java.util.List;

public class sample_2575 {
    public static List<Integer> generate_altitude_sequence(int start, int end, int step) {
        List<Integer> sequence = new ArrayList<>();
        int current = start;
        while (current <= end) {
            sequence.add(current);
            current += step;
        }
        return sequence;
    }

    public static List<Double> calculate_flight_duration(List<Integer> altitudes, int speed) {
        List<Double> times = new ArrayList<>();
        for (int altitude : altitudes) {
            times.add((double) altitude / speed);
        }
        return times;
    }

    public static void main(String[] args) {
        int start_altitude = 10000;
        int end_altitude = 40000;
        int step_size = 5000;
        int cruise_speed = 1000;
        List<Integer> altitudes = generate_altitude_sequence(start_altitude, end_altitude, step_size);
        List<Double> durations = calculate_flight_duration(altitudes, cruise_speed);
        for (int i = 0; i < altitudes.size(); i++) {
            System.out.printf("Altitude: %dm, Duration: %.2fs%n", altitudes.get(i), durations.get(i));
        }
    }
}