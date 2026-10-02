import java.lang.Math;

class FlightTrajectory {
    double a;
    double v;
    double t;
    double g;
    double w;

    FlightTrajectory(double initial_altitude, double speed, double angle, double gravity, double wind_speed) {
        this.a = initial_altitude;
        this.v = speed;
        this.t = angle;
        this.g = gravity;
        this.w = wind_speed;
    }

    double calculate_time_to_cruise() {
        double t = 2 * this.a * Math.sin(this.t) / this.g;
        return t;
    }

    double adjust_for_wind(double time) {
        double adjusted_time = time / (1 + this.w / this.v);
        return adjusted_time;
    }
}

class CruiseAltitude {
    double b;
    double i;
    double m;

    CruiseAltitude(double base_altitude, double altitude_increment, double max_altitude) {
        this.b = base_altitude;
        this.i = altitude_increment;
        this.m = max_altitude;
    }

    double determine_cruise_altitude(double time) {
        double alt = this.b + this.i * time;
        if (alt > this.m) {
            return this.m;
        }
        return alt;
    }
}

public class sample_2330 {
    public static void main(String[] args) {
        double initial_altitude = 1000.0;
        double speed = 250.0;
        double angle = Math.toRadians(30);
        double gravity = 9.81;
        double wind_speed = 10.0;
        double base_altitude = 10000.0;
        double altitude_increment = 500.0;
        double max_altitude = 30000.0;
        FlightTrajectory trajectory = new FlightTrajectory(initial_altitude, speed, angle, gravity, wind_speed);
        CruiseAltitude cruise_altitude = new CruiseAltitude(base_altitude, altitude_increment, max_altitude);
        while (true) {
            double time = trajectory.calculate_time_to_cruise();
            double adjusted_time = trajectory.adjust_for_wind(time);
            double current_altitude = cruise_altitude.determine_cruise_altitude(adjusted_time);
            System.out.println("Current Altitude: " + current_altitude);
        }
    }
}