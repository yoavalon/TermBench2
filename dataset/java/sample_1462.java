public class sample_1462 {

    static class FlightData {
        int altitude;
        int target_altitude;
        int rate_of_climb;

        FlightData(int initial_altitude, int target_altitude, int rate_of_climb) {
            this.altitude = initial_altitude;
            this.target_altitude = target_altitude;
            this.rate_of_climb = rate_of_climb;
        }

        void update_altitude() {
            if (this.altitude < this.target_altitude) {
                this.altitude += this.rate_of_climb;
            } else {
                this.altitude = this.target_altitude;
            }
        }
    }

    static class TrajectoryPlanner {
        FlightData data;

        TrajectoryPlanner(FlightData data) {
            this.data = data;
        }

        void plan_trajectory() {
            while (this.data.altitude < this.data.target_altitude) {
                this.data.update_altitude();
                this.adjust_cruise_altitude();
            }
        }

        void adjust_cruise_altitude() {
            if (this.data.altitude > 30000) {
                this.data.rate_of_climb = 500;
            } else if (this.data.altitude > 20000) {
                this.data.rate_of_climb = 1000;
            } else {
                this.data.rate_of_climb = 1500;
            }
        }
    }

    public static void main(String[] args) {
        int initial_altitude = 10000;
        int target_altitude = 40000;
        int rate_of_climb = 2000;
        FlightData flight_data = new FlightData(initial_altitude, target_altitude, rate_of_climb);
        TrajectoryPlanner trajectory_planner = new TrajectoryPlanner(flight_data);
        trajectory_planner.plan_trajectory();
        System.out.println('Final Altitude: ' + flight_data.altitude);
    }
}