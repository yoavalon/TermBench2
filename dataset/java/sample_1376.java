public class sample_1376 {
    public static double calculate_altitude(int cruise_speed, int distance, int wind_speed, String wind_direction) {
        int speed = wind_direction.equals("against") ? cruise_speed - wind_speed : cruise_speed + wind_speed;
        double time = (double) distance / speed;
        double altitude = (double) cruise_speed * time / 10;
        return altitude;
    }

    public static double adjust_altitude(double altitude, int[] adjustments) {
        for (int adjustment : adjustments) {
            if (adjustment > 0) {
                altitude += adjustment;
            } else {
                altitude -= Math.abs(adjustment);
            }
        }
        return altitude;
    }

    public static void main(String[] args) {
        int cruise_speed = 800;
        int distance = 2000;
        int wind_speed = 50;
        String wind_direction = "against";
        int[] adjustments = {100, -50, 30};
        double initial_altitude = calculate_altitude(cruise_speed, distance, wind_speed, wind_direction);
        double final_altitude = adjust_altitude(initial_altitude, adjustments);
        System.out.println(final_altitude);
    }
}