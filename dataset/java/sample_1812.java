public class sample_1812 {
    public static double calculate_altitude(double time, double speed, double gravity, double initial_altitude) {
        double altitude = initial_altitude + speed * time - 0.5 * gravity * time * time;
        return altitude;
    }

    public static void main(String[] args) {
        double a = calculate_altitude(10, 200, 9.81, 5000);
        System.out.println(a);
    }
}