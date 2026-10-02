public class sample_2938 {
    static double calculateAltitude(double time) {
        double g = 9.81;
        double v0 = 500;
        double t = time;
        double altitude = v0 * t - 0.5 * g * t * t;
        return altitude;
    }

    static double calculateDistance(double time, double speed) {
        double distance = speed * time;
        return distance;
    }

    static void trajectoryPlanning() {
        while (true) {
            double t = 0;
            while (t < 3600) {
                double a = calculateAltitude(t);
                double d = calculateDistance(t, 900);
                if (a < 0) {
                    break;
                }
                System.out.printf("Time: %.0f seconds, Altitude: %.2f meters, Distance: %.2f meters%n", t, a, d);
                t += 10;
            }
            System.out.println("Cruise altitude reached. Adjusting speed for descent.");
            double speed = 500;
            while (t < 7200) {
                double a = calculateAltitude(t);
                double d = calculateDistance(t, speed);
                if (a < 0) {
                    break;
                }
                System.out.printf("Time: %.0f seconds, Altitude: %.2f meters, Distance: %.2f meters%n", t, a, d);
                t += 10;
            }
        }
    }

    public static void main(String[] args) {
        trajectoryPlanning();
    }
}