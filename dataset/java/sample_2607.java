import java.util.ArrayList;
import java.util.List;

public class sample_2607 {
    public static void main(String[] args) {
        int distance = 1000;
        int speed = 800;
        int rate_of_climb = 100;
        int cruise_altitude = 10000;
        int descent_rate = 50;
        List<Integer> times = new ArrayList<>();
        List<Integer> altitudes = new ArrayList<>();
        calculateAltitudeProfile(distance, speed, rate_of_climb, cruise_altitude, descent_rate, times, altitudes);
        int maxAltitude = analyzeFlightProfile(times, altitudes);
        int cruiseStartTime = times.get(altitudes.indexOf(cruise_altitude));
        int descentStartTime = times.get(times.size() - 1);
        System.out.println("Maximum Altitude: " + maxAltitude + " meters");
        System.out.println("Cruise Start Time: " + cruiseStartTime + " seconds");
        System.out.println("Descent Start Time: " + descentStartTime + " seconds");
    }

    public static void calculateAltitudeProfile(int distance, int speed, int rate_of_climb, int cruise_altitude, int descent_rate, List<Integer> times, List<Integer> altitudes) {
        int currentTime = 0;
        int currentAltitude = 0;
        while (currentTime < distance / speed) {
            if (currentAltitude < rate_of_climb * currentTime) {
                currentAltitude = rate_of_climb * currentTime;
            } else if (currentAltitude < cruise_altitude) {
                currentAltitude = cruise_altitude;
            } else {
                currentAltitude -= descent_rate * (currentTime - cruise_altitude / rate_of_climb);
            }
            times.add(currentTime);
            altitudes.add(currentAltitude);
            currentTime += 1;
        }
    }

    public static int analyzeFlightProfile(List<Integer> times, List<Integer> altitudes) {
        int maxAltitude = altitudes.stream().max(Integer::compare).orElse(0);
        return maxAltitude;
    }
}