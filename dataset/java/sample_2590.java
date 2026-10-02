public class sample_2590 {
    public static int calculateAltitudeChange(int currentAlt, int targetAlt, int rate) {
        if (currentAlt < targetAlt) {
            return Math.min(currentAlt + rate, targetAlt);
        } else {
            return Math.max(currentAlt - rate, targetAlt);
        }
    }

    public static int[] simulateFlightTrajectory(int initialAlt, int targetAlt, int rate, int steps) {
        int altitude = initialAlt;
        int[] trajectory = new int[steps + 1];
        trajectory[0] = altitude;
        for (int i = 1; i <= steps; i++) {
            altitude = calculateAltitudeChange(altitude, targetAlt, rate);
            trajectory[i] = altitude;
            if (altitude == targetAlt) {
                break;
            }
        }
        return trajectory;
    }

    public static void main(String[] args) {
        int initialAltitude = 10000;
        int targetAltitude = 30000;
        int rateOfChange = 1500;
        int simulationSteps = 100;
        int[] result = simulateFlightTrajectory(initialAltitude, targetAltitude, rateOfChange, simulationSteps);
        for (int altitude : result) {
            System.out.print(altitude + " ");
        }
    }
}