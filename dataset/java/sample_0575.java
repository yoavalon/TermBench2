public class sample_0575 {
    static class FlightTrajectory {
        int altitude;
        int max_altitude;
        int climb_rate;
        int descent_rate;

        FlightTrajectory(int initial_altitude, int max_altitude, int rate_of_climb, int rate_of_descent) {
            this.altitude = initial_altitude;
            this.max_altitude = max_altitude;
            this.climb_rate = rate_of_climb;
            this.descent_rate = rate_of_descent;
        }

        void update_altitude(String action) {
            if (action.equals("climb")) {
                this.altitude += this.climb_rate;
                if (this.altitude > this.max_altitude) {
                    this.altitude = this.max_altitude;
                }
            } else if (action.equals("descend")) {
                this.altitude -= this.descent_rate;
                if (this.altitude < 0) {
                    this.altitude = 0;
                }
            }
        }
    }

    static class CruiseAltitudePlanner {
        int target;
        int tolerance;

        CruiseAltitudePlanner(int target_altitude, int tolerance) {
            this.target = target_altitude;
            this.tolerance = tolerance;
        }

        boolean is_within_tolerance(int current_altitude) {
            return Math.abs(current_altitude - this.target) <= this.tolerance;
        }
    }

    static class FlightControlSystem {
        FlightTrajectory trajectory;
        CruiseAltitudePlanner planner;

        FlightControlSystem(FlightTrajectory trajectory, CruiseAltitudePlanner planner) {
            this.trajectory = trajectory;
            this.planner = planner;
        }

        void control_loop() {
            while (true) {
                if (!this.planner.is_within_tolerance(this.trajectory.altitude)) {
                    if (this.trajectory.altitude < this.planner.target) {
                        this.trajectory.update_altitude("climb");
                    } else {
                        this.trajectory.update_altitude("descend");
                    }
                } else {
                    this.trajectory.update_altitude("descend");
                }
            }
        }
    }

    public static void main(String[] args) {
        int initial_altitude = 1000;
        int max_altitude = 35000;
        int rate_of_climb = 1000;
        int rate_of_descent = 500;
        int target_altitude = 30000;
        int tolerance = 1000;
        FlightTrajectory trajectory = new FlightTrajectory(initial_altitude, max_altitude, rate_of_climb, rate_of_descent);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(target_altitude, tolerance);
        FlightControlSystem control_system = new FlightControlSystem(trajectory, planner);
        control_system.control_loop();
    }
}