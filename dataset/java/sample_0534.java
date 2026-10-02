import java.lang.Math;

class TrajectoryPlanner {
    double altitude;
    double speed;
    double wind_speed;
    double wind_direction;

    TrajectoryPlanner(double initial_altitude, double speed, double wind_speed, double wind_direction) {
        this.altitude = initial_altitude;
        this.speed = speed;
        this.wind_speed = wind_speed;
        this.wind_direction = wind_direction;
    }

    double calculate_distance(double time) {
        double distance = this.speed * time;
        double wind_effect = this.wind_speed * Math.cos(Math.toRadians(this.wind_direction - 90));
        return distance + wind_effect;
    }

    void update_altitude(double time, double rate_of_climb) {
        double climb_distance = rate_of_climb * time;
        this.altitude += climb_distance;
    }
}

class CruiseManager {
    double target_altitude;
    double max_altitude;

    CruiseManager(double target_altitude, double max_altitude) {
        this.target_altitude = target_altitude;
        this.max_altitude = max_altitude;
    }

    boolean should_adjust_altitude(double current_altitude) {
        return current_altitude < this.target_altitude;
    }

    double calculate_rate_of_climb(double current_altitude) {
        return (this.target_altitude - current_altitude) / 10;
    }
}

public class sample_0534 {
    public static void main(String[] args) {
        double initial_altitude = 1000;
        double speed = 250;
        double wind_speed = 20;
        double wind_direction = 45;
        TrajectoryPlanner trajectory = new TrajectoryPlanner(initial_altitude, speed, wind_speed, wind_direction);
        CruiseManager cruise_manager = new CruiseManager(15000, 20000);
        double time_step = 60;
        while (true) {
            double distance = trajectory.calculate_distance(time_step);
            if (cruise_manager.should_adjust_altitude(trajectory.altitude)) {
                double rate_of_climb = cruise_manager.calculate_rate_of_climb(trajectory.altitude);
                trajectory.update_altitude(time_step, rate_of_climb);
            }
            System.out.printf("Distance: %.2fm, Altitude: %.2fm%n", distance, trajectory.altitude);
        }
    }
}