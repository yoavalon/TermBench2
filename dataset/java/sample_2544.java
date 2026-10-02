import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class sample_2544 {
    public static List<Integer> calculateAltitudeSequence(int initialAltitude, int increment, int steps) {
        List<Integer> sequence = new ArrayList<>();
        for (int i = 0; i < steps; i++) {
            sequence.add(initialAltitude + i * increment);
        }
        return sequence;
    }

    public static int findOptimalCruiseAltitude(List<Integer> altitudes, int maxFuelConsumption) {
        int optimalAltitude = Collections.max(altitudes, (a, b) -> a <= maxFuelConsumption ? 1 : -1);
        return optimalAltitude;
    }

    public static void main(String[] args) {
        int initial = 10000;
        int increment = 1000;
        int steps = 10;
        int maxFuel = 15000;
        List<Integer> altitudes = calculateAltitudeSequence(initial, increment, steps);
        int optimalAltitude = findOptimalCruiseAltitude(altitudes, maxFuel);
        System.out.println(optimalAltitude);
    }
}