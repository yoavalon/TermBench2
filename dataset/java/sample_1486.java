public class sample_1486 {
    public static class FlightTrajectory {
        int altitude;
        int target;
        int rate;
        String status;

        public FlightTrajectory(int start_altitude, int target_altitude, int rate_of_climb) {
            this.altitude = start_altitude;
            this.target = target_altitude;
            this.rate = rate_of_climb;
            this.status = "ascending";
        }

        public int update_altitude() {
            if (this.status.equals("ascending")) {
                this.altitude += this.rate;
                if (this.altitude >= this.target) {
                    this.status = "cruising";
                    this.altitude = this.target;
                }
            }
            return this.altitude;
        }

        public boolean is_cruising() {
            return this.status.equals("cruising");
        }
    }

    public static int plan_cruise_altitude(FlightTrajectory trajectory, int max_iterations) {
        int iteration = 0;
        while (iteration < max_iterations && !trajectory.is_cruising()) {
            trajectory.update_altitude();
            iteration += 1;
        }
        return trajectory.altitude;
    }

    public static void main(String[] args) {
        int start = 1000;
        int target = 35000;
        int rate = 500;
        int max_iter = 1000;
        FlightTrajectory trajectory = new FlightTrajectory(start, target, rate);
        int final_altitude = plan_cruise_altitude(trajectory, max_iter);
        System.out.println("Final Cruise Altitude: " + final_altitude);
    }
}