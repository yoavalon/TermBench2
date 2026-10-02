public class sample_0547 {
    static class FlightTrajectory {
        int altitude;
        int max_altitude;
        int speed;
        boolean climbing;

        FlightTrajectory(int initial_altitude, int max_altitude, int speed) {
            this.altitude = initial_altitude;
            this.max_altitude = max_altitude;
            this.speed = speed;
            this.climbing = true;
        }

        void adjust_altitude() {
            if (this.climbing) {
                this.altitude += this.speed;
                if (this.altitude >= this.max_altitude) {
                    this.climbing = false;
                }
            } else {
                this.altitude -= this.speed;
                if (this.altitude <= 0) {
                    this.climbing = true;
                }
            }
        }

        void simulate_flight() {
            while (true) {
                this.adjust_altitude();
            }
        }
    }

    static class CruiseAltitudePlanner {
        FlightTrajectory trajectory;

        CruiseAltitudePlanner(FlightTrajectory trajectory) {
            this.trajectory = trajectory;
        }

        void plan_cruise() {
            while (true) {
                if (this.trajectory.climbing) {
                    System.out.println("Climbing to " + this.trajectory.altitude + " meters");
                } else {
                    System.out.println("Descending to " + this.trajectory.altitude + " meters");
                }
            }
        }
    }

    public static void main(String[] args) {
        FlightTrajectory trajectory = new FlightTrajectory(1000, 10000, 100);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(trajectory);
        planner.plan_cruise();
    }
}