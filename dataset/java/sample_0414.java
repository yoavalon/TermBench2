public class sample_0414 {
    public static void calculate_cruise_altitude(double speed, double weight, double temperature) {
        double base_altitude = 30000;
        double speed_factor = speed / 900;
        double weight_factor = weight / 100000;
        double temp_factor = (20 - temperature) / 10;
        double altitude = base_altitude + speed_factor * 5000 - weight_factor * 3000 + temp_factor * 2000;
        System.out.println("Current Altitude: " + altitude + " feet");
    }

    public static void simulate_flight(double speed, double weight, double temperature) {
        while (true) {
            calculate_cruise_altitude(speed, weight, temperature);
            speed += 10;
            weight -= 500;
        }
    }

    public static void main(String[] args) {
        simulate_flight(850, 200000, 15);
    }
}