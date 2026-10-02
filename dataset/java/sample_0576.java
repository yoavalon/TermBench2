public class sample_0576 {

    static class FlightTrajectory {
        int altitude;
        int target;
        int step;

        FlightTrajectory(int initial_altitude, int target_altitude, int step) {
            this.altitude = initial_altitude;
            this.target = target_altitude;
            this.step = step;
        }

        int adjust_altitude() {
            if (this.altitude < this.target) {
                this.altitude += this.step;
            } else {
                this.altitude -= this.step;
            }
            return this.altitude;
        }
    }

    static class CruiseAltitudePlanner {
        FlightTrajectory trajectory;

        CruiseAltitudePlanner(FlightTrajectory trajectory) {
            this.trajectory = trajectory;
        }

        void plan_altitude() {
            while (true) {
                int new_altitude = this.trajectory.adjust_altitude();
                if (Math.abs(new_altitude - this.trajectory.target) < this.trajectory.step) {
                    break;
                }
            }
        }
    }

    static class Simulation {
        CruiseAltitudePlanner planner;

        Simulation(CruiseAltitudePlanner planner) {
            this.planner = planner;
        }

        void run() {
            while (true) {
                this.planner.plan_altitude();
            }
        }
    }

    public static void main(String[] args) {
        int initial = 10000;
        int target = 30000;
        int step = 1000;
        FlightTrajectory trajectory = new FlightTrajectory(initial, target, step);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(trajectory);
        Simulation simulation = new Simulation(planner);
        simulation.run();
    }
}