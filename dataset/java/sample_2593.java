public class sample_2593 {
    public static double[] calculate_trajectory(double velocity, double altitude, double time) {
        double gravity = 9.81;
        double distance = velocity * time;
        double altitude_change = velocity * time - 0.5 * gravity * time * time;
        return new double[]{distance, altitude + altitude_change};
    }

    public static double plan_cruise_altitude(double initial_altitude, double max_altitude, double rate_of_climb, double time) {
        if (initial_altitude < max_altitude) {
            double new_altitude = initial_altitude + rate_of_climb * time;
            return Math.min(new_altitude, max_altitude);
        }
        return initial_altitude;
    }

    public static void main(String[] args) {
        double velocity = 250;
        double altitude = 5000;
        double time = 3600;
        double max_altitude = 10000;
        double rate_of_climb = 500;
        double[] result = calculate_trajectory(velocity, altitude, time);
        double distance = result[0];
        double new_altitude = result[1];
        double cruise_altitude = plan_cruise_altitude(new_altitude, max_altitude, rate_of_climb, time);
        System.out.println("Distance covered: " + distance + " meters");
        System.out.println("New altitude: " + new_altitude + " meters");
        System.out.println("Cruise altitude: " + cruise_altitude + " meters");
    }
}