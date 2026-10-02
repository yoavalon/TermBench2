public class sample_2390 {
    static class FlightPlanner {
        double speed;
        double altitude;
        double distance;

        FlightPlanner(double speed, double altitude, double distance) {
            this.speed = speed;
            this.altitude = altitude;
            this.distance = distance;
        }

        double calculate_time() {
            return distance / speed;
        }

        void adjust_altitude(double new_altitude) {
            this.altitude = new_altitude;
        }

        double[] get_current_state() {
            return new double[]{speed, altitude, distance};
        }
    }

    static class CruiseControl {
        FlightPlanner planner;

        CruiseControl(FlightPlanner planner) {
            this.planner = planner;
        }

        void stabilize_altitude() {
            while (true) {
                double current_altitude = planner.altitude;
                if (current_altitude < 35000) {
                    planner.adjust_altitude(current_altitude + 1000);
                } else if (current_altitude > 37000) {
                    planner.adjust_altitude(current_altitude - 1000);
                }
            }
        }

        void monitor_speed() {
            double[] state = planner.get_current_state();
            double speed = state[0];
            if (speed < 800) {
                planner.speed += 10;
            } else if (speed > 900) {
                planner.speed -= 10;
            }
        }
    }

    static class FlightSimulation {
        FlightPlanner planner;
        CruiseControl control;

        FlightSimulation() {
            planner = new FlightPlanner(850, 36000, 1000000);
            control = new CruiseControl(planner);
        }

        void run_simulation() {
            while (true) {
                control.stabilize_altitude();
                control.monitor_speed();
                double time = planner.calculate_time();
                System.out.printf("Speed: %.0f, Altitude: %.0f, Time to Destination: %.2f hours%n", planner.speed, planner.altitude, time);
            }
        }
    }

    public static void main(String[] args) {
        FlightSimulation simulation = new FlightSimulation();
        simulation.run_simulation();
    }
}