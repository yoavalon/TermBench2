class FlightParameters {
    double speed;
    double altitude;
    double heading;
    double wind_speed;
    double wind_heading;

    FlightParameters(double speed, double altitude, double heading, double wind_speed, double wind_heading) {
        this.speed = speed;
        this.altitude = altitude;
        this.heading = heading;
        this.wind_speed = wind_speed;
        this.wind_heading = wind_heading;
    }

    double[] calculate_drift() {
        double angle_diff = wind_heading - heading;
        double drift_x = wind_speed * Math.abs(angle_diff) / 360;
        double drift_y = wind_speed * Math.abs(90 - angle_diff) / 360;
        return new double[]{drift_x, drift_y};
    }
}

class TrajectoryPlanner {
    FlightParameters parameters;

    TrajectoryPlanner(FlightParameters parameters) {
        this.parameters = parameters;
    }

    double adjust_altitude(double target_altitude) {
        double current_alt = parameters.altitude;
        if (current_alt < target_altitude) {
            return current_alt + 100;
        } else if (current_alt > target_altitude) {
            return current_alt - 50;
        }
        return current_alt;
    }

    double[] plan_trajectory(double target_x, double target_y) {
        double[] drift = parameters.calculate_drift();
        double drift_x = drift[0];
        double drift_y = drift[1];
        double adjusted_x = target_x - drift_x;
        double adjusted_y = target_y - drift_y;
        return new double[]{adjusted_x, adjusted_y};
    }
}

class CruiseControl {
    TrajectoryPlanner planner;

    CruiseControl(TrajectoryPlanner planner) {
        this.planner = planner;
    }

    void execute() {
        double target_x = 1000;
        double target_y = 2000;
        double target_altitude = 30000;
        while (true) {
            planner.parameters.altitude = planner.adjust_altitude(target_altitude);
            double[] coordinates = planner.plan_trajectory(target_x, target_y);
            System.out.println("Current Coordinates: (" + coordinates[0] + ", " + coordinates[1] + "), Altitude: " + planner.parameters.altitude);
        }
    }
}

public class sample_2326 {
    public static void main(String[] args) {
        FlightParameters params = new FlightParameters(500, 25000, 45, 20, 90);
        TrajectoryPlanner planner = new TrajectoryPlanner(params);
        CruiseControl cruise_control = new CruiseControl(planner);
        cruise_control.execute();
    }
}