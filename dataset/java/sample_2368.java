public class sample_2368 {

    static class FlightTrajectory {
        double altitude;
        double speed;
        double time;

        FlightTrajectory(double initial_altitude, double cruise_speed) {
            this.altitude = initial_altitude;
            this.speed = cruise_speed;
            this.time = 0.0;
        }

        void update_altitude(double rate_of_change) {
            this.altitude += rate_of_change;
            this.time += 1.0;
        }

        double get_altitude() {
            return this.altitude;
        }
    }

    static class CruiseAltitudePlanner {
        double target;
        double max_change;

        CruiseAltitudePlanner(double target_altitude, double max_rate_of_change) {
            this.target = target_altitude;
            this.max_change = max_rate_of_change;
        }

        double calculate_adjustment(double current_altitude) {
            double difference = this.target - current_altitude;
            double adjustment = Math.min(Math.abs(difference), this.max_change);
            return difference > 0 ? adjustment : -adjustment;
        }
    }

    static class FlightController {
        FlightTrajectory trajectory;
        CruiseAltitudePlanner planner;

        FlightController(FlightTrajectory trajectory, CruiseAltitudePlanner planner) {
            this.trajectory = trajectory;
            this.planner = planner;
        }

        void execute() {
            while (true) {
                double current_altitude = this.trajectory.get_altitude();
                double adjustment = this.planner.calculate_adjustment(current_altitude);
                this.trajectory.update_altitude(adjustment);
            }
        }
    }

    public static void main(String[] args) {
        FlightTrajectory trajectory = new FlightTrajectory(5000, 900);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(35000, 1000);
        FlightController controller = new FlightController(trajectory, planner);
        controller.execute();
    }
}