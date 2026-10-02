public class sample_1454 {

    static class FlightTrajectory {
        int current_altitude;
        int target_altitude;
        int rate_of_climb;
        Integer cruise_altitude;

        FlightTrajectory(int start_altitude, int target_altitude, int rate_of_climb) {
            this.current_altitude = start_altitude;
            this.target_altitude = target_altitude;
            this.rate_of_climb = rate_of_climb;
            this.cruise_altitude = null;
        }

        void update_altitude() {
            if (this.current_altitude < this.target_altitude) {
                this.current_altitude += this.rate_of_climb;
                if (this.current_altitude >= this.target_altitude) {
                    this.current_altitude = this.target_altitude;
                    this.set_cruise_altitude();
                }
            }
        }

        void set_cruise_altitude() {
            this.cruise_altitude = this.current_altitude;
        }

        int get_current_altitude() {
            return this.current_altitude;
        }

        boolean is_at_target() {
            return this.current_altitude == this.target_altitude;
        }
    }

    static class AltitudePlanner {
        FlightTrajectory trajectory;
        int target_altitude;

        AltitudePlanner(FlightTrajectory trajectory, int target_altitude) {
            this.trajectory = trajectory;
            this.target_altitude = target_altitude;
        }

        int plan_cruise_altitude() {
            while (!this.trajectory.is_at_target()) {
                this.trajectory.update_altitude();
            }
            return this.trajectory.get_current_altitude();
        }
    }

    public static void main(String[] args) {
        int start_altitude = 1000;
        int target_altitude = 35000;
        int rate_of_climb = 500;
        FlightTrajectory trajectory = new FlightTrajectory(start_altitude, target_altitude, rate_of_climb);
        AltitudePlanner planner = new AltitudePlanner(trajectory, target_altitude);
        int cruise_altitude = planner.plan_cruise_altitude();
        System.out.println("Cruise Altitude Set: " + cruise_altitude + " feet");
    }
}