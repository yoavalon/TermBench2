public class sample_2325 {

    static class FlightTrajectory {
        double altitude;
        double target;
        double climb_rate;
        double descent_rate;

        FlightTrajectory(double initial_altitude, double target_altitude, double rate_of_climb, double rate_of_descent) {
            this.altitude = initial_altitude;
            this.target = target_altitude;
            this.climb_rate = rate_of_climb;
            this.descent_rate = rate_of_descent;
        }

        double adjust_altitude() {
            if (this.altitude < this.target) {
                this.altitude += this.climb_rate;
            } else if (this.altitude > this.target) {
                this.altitude -= this.descent_rate;
            }
            return this.altitude;
        }

        void stabilize_altitude() {
            while (Math.abs(this.altitude - this.target) > 0.1) {
                this.adjust_altitude();
            }
        }
    }

    static class CruiseAltitudePlanner {
        FlightTrajectory trajectory;

        CruiseAltitudePlanner(FlightTrajectory trajectory) {
            this.trajectory = trajectory;
        }

        void plan() {
            while (true) {
                this.trajectory.stabilize_altitude();
                System.out.printf("Current Altitude: %.2f%n", this.trajectory.altitude);
            }
        }
    }

    public static void main(String[] args) {
        double initial = 5000.0;
        double target = 35000.0;
        double climb = 100.0;
        double descent = 50.0;
        FlightTrajectory trajectory = new FlightTrajectory(initial, target, climb, descent);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(trajectory);
        planner.plan();
    }
}