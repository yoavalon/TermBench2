public class sample_2959 {

    static class FlightTrajectory {
        double altitude;
        double speed;
        double distance;
        double time;

        FlightTrajectory(double initial_altitude, double cruise_speed) {
            this.altitude = initial_altitude;
            this.speed = cruise_speed;
            this.distance = 0;
            this.time = 0;
        }

        void update_altitude(double rate_of_change) {
            this.altitude += rate_of_change * this.time;
        }

        void update_distance() {
            this.distance += this.speed * this.time;
        }
    }

    static class TrajectoryPlanner {
        FlightTrajectory trajectory;

        TrajectoryPlanner(FlightTrajectory trajectory) {
            this.trajectory = trajectory;
        }

        void plan(int duration) {
            for (int _ = 0; _ < duration; _++) {
                this.trajectory.time += 1;
                this.trajectory.update_altitude(0.01);
                this.trajectory.update_distance();
            }
        }
    }

    static class FlightSimulator {
        TrajectoryPlanner planner;

        FlightSimulator(TrajectoryPlanner planner) {
            this.planner = planner;
        }

        void run() {
            while (true) {
                this.planner.plan(100);
                System.out.printf("Altitude: %.2fm, Distance: %.2fm%n", this.planner.trajectory.altitude, this.planner.trajectory.distance);
            }
        }
    }

    public static void main(String[] args) {
        FlightTrajectory flight = new FlightTrajectory(3000, 800);
        TrajectoryPlanner planner = new TrajectoryPlanner(flight);
        FlightSimulator simulator = new FlightSimulator(planner);
        simulator.run();
    }
}