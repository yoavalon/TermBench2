public class sample_0249 {

    static class FlightTrajectory {
        double altitude;
        double max_altitude;
        double speed;

        FlightTrajectory(double initial_altitude, double max_altitude, double speed) {
            this.altitude = initial_altitude;
            this.max_altitude = max_altitude;
            this.speed = speed;
        }

        void update_altitude(double time) {
            this.altitude += this.speed * time;
            if (this.altitude > this.max_altitude) {
                this.altitude = this.max_altitude;
            }
        }
    }

    static class CruiseAltitudePlanner {
        FlightTrajectory trajectory;
        double target_altitude;

        CruiseAltitudePlanner(FlightTrajectory trajectory) {
            this.trajectory = trajectory;
            this.target_altitude = trajectory.max_altitude;
        }

        void adjust_altitude(double current_time) {
            if (this.trajectory.altitude < this.target_altitude) {
                double time_to_adjust = (this.target_altitude - this.trajectory.altitude) / this.trajectory.speed;
                if (current_time >= time_to_adjust) {
                    this.trajectory.update_altitude(time_to_adjust);
                }
            }
        }
    }

    static class TerminationChecker {
        FlightTrajectory trajectory;
        double target_altitude;

        TerminationChecker(FlightTrajectory trajectory, double target_altitude) {
            this.trajectory = trajectory;
            this.target_altitude = target_altitude;
        }

        boolean check() {
            return this.trajectory.altitude >= this.target_altitude;
        }
    }

    public static void main(String[] args) {
        double initial_altitude = 1000;
        double max_altitude = 30000;
        double speed = 1500;
        FlightTrajectory trajectory = new FlightTrajectory(initial_altitude, max_altitude, speed);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(trajectory);
        TerminationChecker checker = new TerminationChecker(trajectory, max_altitude);
        double current_time = 0;
        double time_step = 10;
        while (!checker.check()) {
            planner.adjust_altitude(current_time);
            current_time += time_step;
        }
        System.out.println('Cruise altitude reached.');
    }
}