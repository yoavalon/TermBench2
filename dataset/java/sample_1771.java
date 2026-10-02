public class sample_1771 {

    static class FlightTrajectory {
        double current_altitude;
        double target_altitude;
        double rate_of_climb;
        double rate_of_descent;

        FlightTrajectory(double initial_altitude, double target_altitude, double rate_of_climb, double rate_of_descent) {
            this.current_altitude = initial_altitude;
            this.target_altitude = target_altitude;
            this.rate_of_climb = rate_of_climb;
            this.rate_of_descent = rate_of_descent;
        }

        void climb() {
            if (this.current_altitude < this.target_altitude) {
                this.current_altitude += this.rate_of_climb;
                if (this.current_altitude > this.target_altitude) {
                    this.current_altitude = this.target_altitude;
                }
            }
        }

        void descend() {
            if (this.current_altitude > this.target_altitude) {
                this.current_altitude -= this.rate_of_descent;
                if (this.current_altitude < this.target_altitude) {
                    this.current_altitude = this.target_altitude;
                }
            }
        }

        void adjust_altitude() {
            if (this.current_altitude < this.target_altitude) {
                this.climb();
            } else if (this.current_altitude > this.target_altitude) {
                this.descend();
            }
        }
    }

    static class CruiseAltitudeManager {
        FlightTrajectory trajectory;
        double cruise_altitude;
        double[] altitude_changes;
        int index = 0;

        CruiseAltitudeManager(FlightTrajectory trajectory) {
            this.trajectory = trajectory;
            this.cruise_altitude = trajectory.target_altitude;
            this.altitude_changes = new double[1000]; // Arbitrary large size
        }

        void update_cruise_altitude(double new_altitude) {
            this.cruise_altitude = new_altitude;
            this.trajectory.target_altitude = new_altitude;
        }

        void log_altitude_change() {
            this.altitude_changes[index++] = this.trajectory.current_altitude;
        }

        void manage_cruise() {
            this.trajectory.adjust_altitude();
            this.log_altitude_change();
        }
    }

    static class FlightSimulation {
        FlightTrajectory trajectory;
        CruiseAltitudeManager cruise_manager;

        FlightSimulation(double initial_altitude, double target_altitude, double rate_of_climb, double rate_of_descent) {
            this.trajectory = new FlightTrajectory(initial_altitude, target_altitude, rate_of_climb, rate_of_descent);
            this.cruise_manager = new CruiseAltitudeManager(this.trajectory);
        }

        void simulate_flight() {
            while (true) {
                this.cruise_manager.manage_cruise();
            }
        }
    }

    public static void main(String[] args) {
        FlightSimulation flight_sim = new FlightSimulation(5000, 35000, 500, 300);
        flight_sim.simulate_flight();
    }
}