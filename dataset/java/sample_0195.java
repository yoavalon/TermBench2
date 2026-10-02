public class sample_0195 {
    public static double calculate_altitude(double velocity, double angle) {
        double g = 9.81;
        double altitude = velocity * velocity * (2 * angle) / (g * 3600);
        return altitude;
    }

    public static String evaluate_boundary_conditions(double velocity, double angle) {
        if (velocity < 100 || angle < 5) {
            return 'Conditions not met';
        } else {
            return 'Conditions met';
        }
    }

    public static void main(String[] args) {
        double velocity = 500;
        double angle = 15;
        double altitude = calculate_altitude(velocity, angle);
        String condition_status = evaluate_boundary_conditions(velocity, angle);
        System.out.println('Calculated Altitude: ' + altitude);
        System.out.println('Boundary Conditions: ' + condition_status);
    }
}