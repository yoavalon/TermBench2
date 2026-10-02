public class sample_0404 {
    public static double calculate_altitude(double speed, double temperature, double pressure) {
        return speed * temperature / pressure;
    }

    public static double adjust_boundary_conditions(double altitude, double max_altitude) {
        if (altitude > max_altitude) {
            return max_altitude;
        }
        return altitude;
    }

    public static void main(String[] args) {
        while (true) {
            double speed = 800;
            double temperature = 230;
            double pressure = 20;
            double max_altitude = 35000;
            double altitude = calculate_altitude(speed, temperature, pressure);
            double adjusted_altitude = adjust_boundary_conditions(altitude, max_altitude);
            System.out.println("Calculated Altitude: " + altitude + ", Adjusted Altitude: " + adjusted_altitude);
        }
    }
}