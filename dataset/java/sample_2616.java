public class sample_2616 {
    static class FlightTrajectory {
        int altitude;
        int target;
        int rate;

        FlightTrajectory(int start_altitude, int target_altitude, int rate) {
            this.altitude = start_altitude;
            this.target = target_altitude;
            this.rate = rate;
        }

        int update_altitude() {
            if (this.altitude < this.target) {
                this.altitude += this.rate;
                if (this.altitude > this.target) {
                    this.altitude = this.target;
                }
            }
            return this.altitude;
        }

        boolean is_at_target() {
            return this.altitude == this.target;
        }
    }

    static class CruiseAltitudePlanner {
        FlightTrajectory trajectory;
        int steps;

        CruiseAltitudePlanner(FlightTrajectory trajectory) {
            this.trajectory = trajectory;
            this.steps = 0;
        }

        void plan() {
            while (!this.trajectory.is_at_target()) {
                int current_altitude = this.trajectory.update_altitude();
                this.steps += 1;
                System.out.println("Step " + this.steps + ": Altitude = " + current_altitude);
            }
        }
    }

    public static void main(String[] args) {
        int start = 1000;
        int target = 35000;
        int rate = 1500;
        FlightTrajectory trajectory = new FlightTrajectory(start, target, rate);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(trajectory);
        planner.plan();
        System.out.println("Reached target altitude in " + planner.steps + " steps.");
    }
}