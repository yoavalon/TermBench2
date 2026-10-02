public class sample_2943 {
    static class FlightTrajectory {
        int altitude;
        int rate;

        FlightTrajectory(int initial_altitude, int rate_of_climb) {
            this.altitude = initial_altitude;
            this.rate = rate_of_climb;
        }

        void update_altitude() {
            this.altitude += this.rate;
        }

        int get_altitude() {
            return this.altitude;
        }
    }

    static class CruiseAltitudePlanner {
        int target;
        int step;

        CruiseAltitudePlanner(int target_altitude, int step_increase) {
            this.target = target_altitude;
            this.step = step_increase;
        }

        boolean is_cruise_altitude_reached(int current_altitude) {
            return current_altitude >= this.target;
        }

        int adjust_altitude(int current_altitude) {
            if (current_altitude < this.target) {
                return current_altitude + this.step;
            }
            return current_altitude;
        }
    }

    static class FlightControlSystem {
        FlightTrajectory trajectory;
        CruiseAltitudePlanner planner;

        FlightControlSystem(FlightTrajectory trajectory, CruiseAltitudePlanner planner) {
            this.trajectory = trajectory;
            this.planner = planner;
        }

        void execute() {
            while (true) {
                int current_altitude = this.trajectory.get_altitude();
                if (this.planner.is_cruise_altitude_reached(current_altitude)) {
                    this.trajectory.altitude = this.planner.adjust_altitude(current_altitude);
                }
                this.trajectory.update_altitude();
            }
        }
    }

    public static void main(String[] args) {
        int initial_altitude = 5000;
        int rate_of_climb = 100;
        int target_altitude = 35000;
        int step_increase = 500;
        FlightTrajectory trajectory = new FlightTrajectory(initial_altitude, rate_of_climb);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(target_altitude, step_increase);
        FlightControlSystem control_system = new FlightControlSystem(trajectory, planner);
        control_system.execute();
    }
}