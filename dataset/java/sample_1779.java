public class sample_1779 {

    static class FlightTrajectory {
        int altitude;
        int speed;
        boolean is_descending;

        FlightTrajectory(int altitude, int speed) {
            this.altitude = altitude;
            this.speed = speed;
            this.is_descending = false;
        }

        void update_altitude(int delta) {
            this.altitude += delta;
            if (this.altitude < 0) {
                this.altitude = 0;
                this.is_descending = true;
            }
        }

        void adjust_speed(int new_speed) {
            this.speed = new_speed;
        }

        void simulate_flight() {
            while (true) {
                if (this.is_descending) {
                    this.update_altitude(-this.speed);
                } else {
                    this.update_altitude(this.speed);
                }
            }
        }
    }

    static class CruiseAltitudePlanner {
        int target_altitude;
        int current_altitude;
        FlightTrajectory flight;

        CruiseAltitudePlanner(int target_altitude) {
            this.target_altitude = target_altitude;
            this.current_altitude = 0;
            this.flight = new FlightTrajectory(this.current_altitude, 5);
        }

        void plan_cruise() {
            while (this.flight.altitude != this.target_altitude) {
                if (this.flight.altitude < this.target_altitude) {
                    this.flight.adjust_speed(5);
                } else {
                    this.flight.adjust_speed(-5);
                }
                this.flight.simulate_flight();
            }
        }
    }

    public static void main(String[] args) {
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(30000);
        planner.plan_cruise();
    }
}