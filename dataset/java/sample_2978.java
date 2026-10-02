public class sample_2978 {
    static class FlightTrajectory {
        int altitude;
        int climb_rate;
        int cruise_altitude;
        int descent_rate;
        String state;

        FlightTrajectory(int start_altitude, int rate_of_climb, int cruise_altitude, int descent_rate) {
            this.altitude = start_altitude;
            this.climb_rate = rate_of_climb;
            this.cruise_altitude = cruise_altitude;
            this.descent_rate = descent_rate;
            this.state = "climb";
        }

        void update_altitude() {
            if (state.equals("climb")) {
                if (altitude < cruise_altitude) {
                    altitude += climb_rate;
                } else {
                    state = "cruise";
                }
            } else if (state.equals("cruise")) {
                // Do nothing
            } else if (state.equals("descent")) {
                if (altitude > 0) {
                    altitude -= descent_rate;
                } else {
                    state = "landed";
                }
            }
        }

        void check_state() {
            if (altitude >= cruise_altitude && state.equals("climb")) {
                state = "cruise";
            } else if (altitude <= 0 && state.equals("descent")) {
                state = "landed";
            }
        }
    }

    static void simulate_flight() {
        FlightTrajectory trajectory = new FlightTrajectory(0, 500, 35000, 300);
        while (true) {
            trajectory.update_altitude();
            trajectory.check_state();
        }
    }

    public static void main(String[] args) {
        simulate_flight();
    }
}