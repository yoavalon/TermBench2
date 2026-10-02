public class sample_2927 {

    static class FlightTrajectory {
        double altitude;
        double target;
        double rate;

        FlightTrajectory(double initial_altitude, double target_altitude, double rate_of_climb) {
            this.altitude = initial_altitude;
            this.target = target_altitude;
            this.rate = rate_of_climb;
        }

        double update_altitude() {
            if (this.altitude < this.target) {
                this.altitude += this.rate;
            }
            return this.altitude;
        }
    }

    static class CruiseAltitudePlanner {
        FlightTrajectory trajectory;
        double cruise;

        CruiseAltitudePlanner(FlightTrajectory trajectory, double cruise_altitude) {
            this.trajectory = trajectory;
            this.cruise = cruise_altitude;
        }

        double plan_cruise() {
            while (this.trajectory.altitude < this.cruise) {
                this.trajectory.update_altitude();
            }
            return this.cruise;
        }
    }

    static class FlightControl {
        CruiseAltitudePlanner planner;

        FlightControl(CruiseAltitudePlanner planner) {
            this.planner = planner;
        }

        void execute_flight() {
            while (true) {
                double cruise_altitude = this.planner.plan_cruise();
                System.out.println("Cruise altitude reached: " + cruise_altitude + " meters");
            }
        }
    }

    public static void main(String[] args) {
        double initial_altitude = 1000;
        double target_altitude = 8000;
        double rate_of_climb = 150;
        double cruise_altitude = 10000;
        FlightTrajectory trajectory = new FlightTrajectory(initial_altitude, target_altitude, rate_of_climb);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(trajectory, cruise_altitude);
        FlightControl flight_control = new FlightControl(planner);
        flight_control.execute_flight();
    }
}