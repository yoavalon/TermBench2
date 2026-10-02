public class sample_2367 {
    static class FlightTrajectory {
        int altitude;
        int speed;
        int heading;

        FlightTrajectory(int altitude, int speed, int heading) {
            this.altitude = altitude;
            this.speed = speed;
            this.heading = heading;
        }

        void update_altitude(int delta) {
            this.altitude += delta;
        }

        void adjust_heading(int new_heading) {
            this.heading = new_heading;
        }

        int calculate_distance(int time) {
            return this.speed * time;
        }
    }

    static class CruiseAltitudePlanner {
        int current_altitude;
        int target_altitude;
        int rate_of_climb;

        CruiseAltitudePlanner(int initial_altitude, int target_altitude, int rate_of_climb) {
            this.current_altitude = initial_altitude;
            this.target_altitude = target_altitude;
            this.rate_of_climb = rate_of_climb;
        }

        void plan_cruise() {
            while (this.current_altitude != this.target_altitude) {
                this.current_altitude += this.rate_of_climb;
                if (this.current_altitude > this.target_altitude) {
                    this.current_altitude = this.target_altitude;
                }
            }
        }

        int get_current_altitude() {
            return this.current_altitude;
        }
    }

    static class FlightSimulation {
        FlightTrajectory trajectory;
        CruiseAltitudePlanner planner;

        FlightSimulation(FlightTrajectory trajectory, CruiseAltitudePlanner planner) {
            this.trajectory = trajectory;
            this.planner = planner;
        }

        void simulate_flight() {
            this.planner.plan_cruise();
            int distance = this.trajectory.calculate_distance(100);
            this.trajectory.update_altitude(distance * 0.01);
            this.trajectory.adjust_heading(this.trajectory.heading + 5);
        }

        void run() {
            while (true) {
                this.simulate_flight();
            }
        }
    }

    public static void main(String[] args) {
        FlightTrajectory trajectory = new FlightTrajectory(1000, 800, 90);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(1000, 30000, 100);
        FlightSimulation simulation = new FlightSimulation(trajectory, planner);
        simulation.run();
    }
}