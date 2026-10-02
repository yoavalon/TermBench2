public class sample_2371 {
    static class FlightPlan {
        double altitude;
        double speed;
        int heading;
        int duration;

        FlightPlan(double altitude, double speed, int heading, int duration) {
            this.altitude = altitude;
            this.speed = speed;
            this.heading = heading;
            this.duration = duration;
        }

        double calculate_distance() {
            double distance = this.speed * this.duration;
            return distance;
        }

        void adjust_altitude(double adjustment) {
            this.altitude += adjustment;
        }
    }

    static class TrajectoryAnalyzer {
        FlightPlan plan;

        TrajectoryAnalyzer(FlightPlan plan) {
            this.plan = plan;
        }

        double[] analyze_cruise() {
            double distance = this.plan.calculate_distance();
            double adjusted_altitude = this.plan.altitude + 0.5;
            return new double[]{distance, adjusted_altitude};
        }
    }

    static class FlightController {
        TrajectoryAnalyzer analyzer;

        FlightController(TrajectoryAnalyzer analyzer) {
            this.analyzer = analyzer;
        }

        void control_cruise() {
            while (true) {
                double[] result = this.analyzer.analyze_cruise();
                double distance = result[0];
                double altitude = result[1];
                System.out.printf("Distance: %.2f, Altitude: %.2f%n", distance, altitude);
            }
        }
    }

    public static void main(String[] args) {
        double altitude = 30000.0;
        double speed = 500.0;
        int heading = 270;
        int duration = 5;
        FlightPlan flight_plan = new FlightPlan(altitude, speed, heading, duration);
        TrajectoryAnalyzer trajectory_analyzer = new TrajectoryAnalyzer(flight_plan);
        FlightController flight_controller = new FlightController(trajectory_analyzer);
        flight_controller.control_cruise();
    }
}