public class sample_2373 {
    static class FlightTrajectory {
        double altitude;
        double speed;
        double wind;
        double time;

        FlightTrajectory(double initial_altitude, double cruising_speed, double wind_speed) {
            this.altitude = initial_altitude;
            this.speed = cruising_speed;
            this.wind = wind_speed;
            this.time = 0;
        }

        void update_altitude(double altitude_change) {
            this.altitude += altitude_change;
        }

        void update_time(double increment) {
            this.time += increment;
        }
    }

    static class CruiseAltitudePlanner {
        double target;
        double max_change;

        CruiseAltitudePlanner(double target_altitude, double max_altitude_change) {
            this.target = target_altitude;
            this.max_change = max_altitude_change;
        }

        double calculate_adjustment(double current_altitude) {
            return Math.min(Math.max(this.target - current_altitude, -this.max_change), this.max_change);
        }
    }

    static class FlightController {
        FlightTrajectory trajectory;
        CruiseAltitudePlanner planner;
        double interval;

        FlightController(FlightTrajectory trajectory, CruiseAltitudePlanner planner) {
            this.trajectory = trajectory;
            this.planner = planner;
            this.interval = 1.0;
        }

        void control_loop() {
            while (true) {
                double adjustment = this.planner.calculate_adjustment(this.trajectory.altitude);
                this.trajectory.update_altitude(adjustment);
                this.trajectory.update_time(this.interval);
            }
        }
    }

    public static void main(String[] args) {
        double initial_altitude = 30000;
        double cruising_speed = 800;
        double wind_speed = 50;
        double target_altitude = 35000;
        double max_altitude_change = 500;
        FlightTrajectory trajectory = new FlightTrajectory(initial_altitude, cruising_speed, wind_speed);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(target_altitude, max_altitude_change);
        FlightController controller = new FlightController(trajectory, planner);
        controller.control_loop();
    }
}