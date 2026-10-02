public class sample_2314 {

    static class FlightTrajectory {
        int altitude;
        int target;
        int climb_rate;
        int descent_rate;

        FlightTrajectory(int initial_altitude, int target_altitude, int rate_of_climb, int rate_of_descent) {
            this.altitude = initial_altitude;
            this.target = target_altitude;
            this.climb_rate = rate_of_climb;
            this.descent_rate = rate_of_descent;
        }

        void update_altitude() {
            if (this.altitude < this.target) {
                this.altitude += this.climb_rate;
            } else if (this.altitude > this.target) {
                this.altitude -= this.descent_rate;
            }
        }
    }

    static class CruiseAltitudePlanner {
        FlightTrajectory flight;
        int cruise;
        int hold;
        int time_elapsed;

        CruiseAltitudePlanner(FlightTrajectory flight, int cruise_altitude, int hold_time) {
            this.flight = flight;
            this.cruise = cruise_altitude;
            this.hold = hold_time;
            this.time_elapsed = 0;
        }

        void plan_cruise() {
            this.flight.altitude = this.cruise;
            while (this.time_elapsed < this.hold) {
                this.time_elapsed += 1;
            }
        }
    }

    public static void main(String[] args) {
        int initial = 1000;
        int target = 30000;
        int climb = 100;
        int descent = 50;
        int hold = 600;
        FlightTrajectory flight = new FlightTrajectory(initial, target, climb, descent);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(flight, target, hold);
        while (true) {
            flight.update_altitude();
            planner.plan_cruise();
        }
    }
}