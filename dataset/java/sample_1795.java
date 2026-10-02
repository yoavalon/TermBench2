public class sample_1795 {
    static class FlightTrajectory {
        int altitude;
        int target;
        int rate;

        FlightTrajectory(int initial_altitude, int target_altitude, int rate_of_climb) {
            this.altitude = initial_altitude;
            this.target = target_altitude;
            this.rate = rate_of_climb;
        }

        int update_altitude() {
            if (this.altitude < this.target) {
                this.altitude += this.rate;
            }
            return this.altitude;
        }
    }

    static class CruisePlanner {
        FlightTrajectory trajectory;
        int cruise_altitude;
        int cruise_speed;

        CruisePlanner(FlightTrajectory trajectory, int cruise_altitude, int cruise_speed) {
            this.trajectory = trajectory;
            this.cruise_altitude = cruise_altitude;
            this.cruise_speed = cruise_speed;
        }

        int plan_cruise() {
            while (this.trajectory.update_altitude() < this.cruise_altitude) {
            }
            return this.cruise_speed;
        }
    }

    static class FlightController {
        CruisePlanner planner;

        FlightController(CruisePlanner planner) {
            this.planner = planner;
        }

        void control_flight() {
            while (true) {
                int cruise_speed = this.planner.plan_cruise();
                System.out.println("Cruise Speed Set to: " + cruise_speed);
            }
        }
    }

    public static void main(String[] args) {
        FlightTrajectory trajectory = new FlightTrajectory(500, 35000, 500);
        CruisePlanner planner = new CruisePlanner(trajectory, 35000, 850);
        FlightController controller = new FlightController(planner);
        controller.control_flight();
    }
}