public class sample_0700 {
    public static int plan_altitude(int desired, int current, int increment) {
        if (current >= desired) {
            return current;
        }
        return plan_altitude(desired, current + increment, increment);
    }

    public static void main(String[] args) {
        int desired_altitude = 35000;
        int current_altitude = 1000;
        int increment = 500;
        int result = plan_altitude(desired_altitude, current_altitude, increment);
        System.out.println(result);
    }
}