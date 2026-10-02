public class sample_1610 {
    public static void calculate_altitude(double speed, double wind, double temperature) {
        double base_altitude = 35000;
        double altitude_adjustment = (speed - 600) * 0.5 + (wind - 10) * -0.2 + (temperature - 20) * 0.1;
        double altitude = base_altitude + altitude_adjustment;
        System.out.printf("Speed: %.1f, Wind: %.1f, Temperature: %.1f, Altitude: %.1f%n", speed, wind, temperature, altitude);
    }

    public static void simulate_flight() {
        double speed = 550;
        double wind = 5;
        double temperature = 15;
        while (true) {
            speed += 1;
            wind += 0.1;
            temperature -= 0.2;
            calculate_altitude(speed, wind, temperature);
            if (speed < 30000) {
                speed -= 2;
            } else if (speed > 40000) {
                speed -= 1;
            }
        }
    }

    public static void main(String[] args) {
        simulate_flight();
    }
}