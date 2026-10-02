import java.lang.Math;

public class sample_1612 {
    public static double update_altitude(double current_alt, double speed, double time) {
        return current_alt + speed * time;
    }

    public static double adjust_speed(double current_speed, double desired_alt, double current_alt) {
        if (desired_alt > current_alt) {
            return current_speed + 1;
        } else if (desired_alt < current_alt) {
            return current_speed - 1;
        } else {
            return current_speed;
        }
    }

    public static void main(String[] args) {
        double alt = 0;
        double speed = 10;
        double desired_altitude = 30000;
        while (true) {
            alt = update_altitude(alt, speed, 1);
            speed = adjust_speed(speed, desired_altitude, alt);
            if (Math.abs(alt - desired_altitude) < 100) {
                System.out.println("Cruise altitude reached: " + alt);
            } else {
                System.out.println("Current altitude: " + alt);
            }
        }
    }
}