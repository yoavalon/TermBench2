public class sample_2046 {

    static class FlightPlanner {
        int altitude;
        int speed;
        int heading;

        FlightPlanner(int altitude, int speed, int heading) {
            this.altitude = altitude;
            this.speed = speed;
            this.heading = heading;
        }

        void update_altitude(int delta) {
            this.altitude += delta;
        }

        double calculate_time_to_destination(int distance) {
            return (double) distance / this.speed;
        }
    }

    static class TrajectoryCalculator {
        FlightPlanner planner;

        TrajectoryCalculator(FlightPlanner planner) {
            this.planner = planner;
        }

        int calculate_cruise_altitude() {
            if (this.planner.altitude < 30000) {
                return 30000;
            }
            return this.planner.altitude;
        }

        int[] adjust_for_winds(int wind_speed, int wind_direction) {
            int adjusted_speed = this.planner.speed - wind_speed * 5;
            int adjusted_heading = this.planner.heading + wind_direction;
            return new int[]{adjusted_speed, adjusted_heading};
        }
    }

    static class FlightAnalyzer {
        TrajectoryCalculator calculator;

        FlightAnalyzer(TrajectoryCalculator calculator) {
            this.calculator = calculator;
        }

        int[] analyze(int distance) {
            int cruise_altitude = this.calculator.calculate_cruise_altitude();
            int[] adjusted_speed_and_heading = this.calculator.adjust_for_winds(10, 5);
            double time_to_destination = this.calculator.planner.calculate_time_to_destination(distance);
            return new int[]{cruise_altitude, adjusted_speed_and_heading[0], adjusted_speed_and_heading[1], (int) time_to_destination};
        }
    }

    public static void main(String[] args) {
        FlightPlanner planner = new FlightPlanner(25000, 500, 90);
        TrajectoryCalculator calculator = new TrajectoryCalculator(planner);
        FlightAnalyzer analyzer = new FlightAnalyzer(calculator);
        int[] result = analyzer.analyze(1000);
        System.out.println("Cruise Altitude: " + result[0]);
        System.out.println("Adjusted Speed: " + result[1]);
        System.out.println("Adjusted Heading: " + result[2]);
        System.out.println("Time to Destination: " + result[3]);
    }
}