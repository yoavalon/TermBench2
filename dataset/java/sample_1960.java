public class sample_1960 {
    public static double calculate_altitude(double speed, double rate) {
        return speed * rate;
    }

    public static double adjust_altitude(double current, double target) {
        double difference = target - current;
        double correction = difference * 0.1;
        return current + correction;
    }

    public static void main(String[] args) {
        double initial_speed = 500.5;
        double rate = 0.8;
        double target_altitude = 45000.0;
        double current_altitude = 0.0;
        for (int i = 0; i < 100; i++) {
            current_altitude = calculate_altitude(initial_speed, rate);
            current_altitude = adjust_altitude(current_altitude, target_altitude);
            if (Math.abs(current_altitude - target_altitude) < 100) {
                break;
            }
        }
        System.out.println(current_altitude);
    }
}