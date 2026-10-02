public class sample_2378 {

    static class FlightTrajectory {
        double altitude;
        double rate;

        FlightTrajectory(double initial_altitude, double rate_of_change) {
            this.altitude = initial_altitude;
            this.rate = rate_of_change;
        }

        void update_altitude() {
            this.altitude += this.rate;
        }

        double get_altitude() {
            return this.altitude;
        }
    }

    static class CruisePlanner {
        double target;

        CruisePlanner(double target_altitude) {
            this.target = target_altitude;
        }

        double evaluate_altitude(double current_altitude) {
            return Math.abs(this.target - current_altitude);
        }

        double adjust_rate(double rate, double error) {
            if (error > 1000) {
                return rate * 1.1;
            } else if (error < 500) {
                return rate * 0.9;
            }
            return rate;
        }
    }

    static class Simulation {
        FlightTrajectory trajectory;
        CruisePlanner planner;

        Simulation(FlightTrajectory trajectory, CruisePlanner planner) {
            this.trajectory = trajectory;
            this.planner = planner;
        }

        void run() {
            while (true) {
                double current_altitude = this.trajectory.get_altitude();
                double error = this.planner.evaluate_altitude(current_altitude);
                if (error < 10) {
                    this.trajectory.rate = 0;
                } else {
                    this.trajectory.rate = this.planner.adjust_rate(this.trajectory.rate, error);
                }
                this.trajectory.update_altitude();
            }
        }
    }

    public static void main(String[] args) {
        double initial_altitude = 1000.0;
        double rate_of_change = 100.0;
        double target_altitude = 30000.0;
        FlightTrajectory trajectory = new FlightTrajectory(initial_altitude, rate_of_change);
        CruisePlanner planner = new CruisePlanner(target_altitude);
        Simulation simulation = new Simulation(trajectory, planner);
        simulation.run();
    }
}