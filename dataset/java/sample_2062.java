public class sample_2062 {

    static class FlightTrajectory {
        double speed;
        double altitude;
        double distance;

        FlightTrajectory(double speed, double altitude, double distance) {
            this.speed = speed;
            this.altitude = altitude;
            this.distance = distance;
        }

        double calculate_time() {
            return this.distance / this.speed;
        }

        void adjust_altitude(double new_altitude) {
            this.altitude = new_altitude;
        }
    }

    static class CruiseAltitudePlanner {
        double max_altitude;
        double min_altitude;
        double step;

        CruiseAltitudePlanner(double max_altitude, double min_altitude, double step) {
            this.max_altitude = max_altitude;
            this.min_altitude = min_altitude;
            this.step = step;
        }

        double[] suggest_altitudes() {
            double[] altitudes = new double[(int)((max_altitude - min_altitude) / step) + 1];
            double current = min_altitude;
            int index = 0;
            while (current <= max_altitude) {
                altitudes[index++] = current;
                current += step;
            }
            return altitudes;
        }
    }

    static double[] optimize_flight_plan(FlightTrajectory trajectory, CruiseAltitudePlanner planner) {
        double[] altitudes = planner.suggest_altitudes();
        double best_time = Double.MAX_VALUE;
        double best_altitude = 0;
        for (double altitude : altitudes) {
            trajectory.adjust_altitude(altitude);
            double time = trajectory.calculate_time();
            if (time < best_time) {
                best_time = time;
                best_altitude = altitude;
            }
        }
        trajectory.adjust_altitude(best_altitude);
        return new double[]{trajectory.altitude, best_time};
    }

    public static void main(String[] args) {
        FlightTrajectory trajectory = new FlightTrajectory(800, 30000, 1000);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(40000, 20000, 5000);
        double[] result = optimize_flight_plan(trajectory, planner);
        System.out.println("Best Altitude: " + result[0] + " meters");
        System.out.println("Time to Destination: " + result[1] + " hours");
    }
}