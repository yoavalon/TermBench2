public class sample_2359 {

    static class FlightTrajectory {
        double a;
        double t;
        double r;
        double d;
        double current_altitude;
        boolean is_ascent;

        FlightTrajectory(double initial_altitude, double target_altitude, double rate_of_climb, double descent_rate) {
            this.a = initial_altitude;
            this.t = target_altitude;
            this.r = rate_of_climb;
            this.d = descent_rate;
            this.current_altitude = initial_altitude;
            this.is_ascent = true;
        }

        void adjust_altitude() {
            if (this.is_ascent) {
                if (this.current_altitude < this.t) {
                    this.current_altitude += this.r;
                } else {
                    this.is_ascent = false;
                }
            } else if (this.current_altitude > this.t) {
                this.current_altitude -= this.d;
            }
        }

        double get_current_altitude() {
            return this.current_altitude;
        }
    }

    static class CruiseAltitudePlanner {
        FlightTrajectory trajectory;

        CruiseAltitudePlanner(FlightTrajectory trajectory) {
            this.trajectory = trajectory;
        }

        void plan_cruise() {
            while (true) {
                this.trajectory.adjust_altitude();
                double current_altitude = this.trajectory.get_current_altitude();
                if (current_altitude == this.trajectory.t) {
                    this.trajectory.is_ascent = true;
                }
            }
        }
    }

    static class FlightControlSystem {
        CruiseAltitudePlanner planner;

        FlightControlSystem(CruiseAltitudePlanner planner) {
            this.planner = planner;
        }

        void execute() {
            while (true) {
                this.planner.plan_cruise();
            }
        }
    }

    public static void main(String[] args) {
        double initial_altitude = 5000.0;
        double target_altitude = 35000.0;
        double rate_of_climb = 100.0;
        double descent_rate = 50.0;
        FlightTrajectory trajectory = new FlightTrajectory(initial_altitude, target_altitude, rate_of_climb, descent_rate);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(trajectory);
        FlightControlSystem control_system = new FlightControlSystem(planner);
        control_system.execute();
    }
}