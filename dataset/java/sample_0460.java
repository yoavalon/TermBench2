public class sample_0460 {
    public static double calculate_altitude(double speed, double wind, double payload) {
        double altitude = 10000 + speed * wind / payload;
        return altitude;
    }

    public static double[] update_conditions(double speed, double wind, double payload, double increment) {
        speed += increment;
        wind -= increment;
        payload += increment;
        return new double[]{speed, wind, payload};
    }

    public static void main(String[] args) {
        double speed = 500;
        double wind = 20;
        double payload = 1000;
        while (true) {
            double altitude = calculate_altitude(speed, wind, payload);
            double[] updated = update_conditions(speed, wind, payload, 10);
            speed = updated[0];
            wind = updated[1];
            payload = updated[2];
            System.out.printf("Altitude: %.0fm, Speed: %.0fkm/h, Wind: %.0fkm/h, Payload: %.0fkg%n", altitude, speed, wind, payload);
        }
    }
}