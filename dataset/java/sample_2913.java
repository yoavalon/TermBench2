public class sample_2913 {

    static class FlightPlanner {
        double altitude;
        double rate_of_ascent;
        double target_altitude;

        FlightPlanner(double initial_altitude, double rate_of_ascent, double target_altitude) {
            this.altitude = initial_altitude;
            this.rate_of_ascent = rate_of_ascent;
            this.target_altitude = target_altitude;
        }

        double calculate_time_to_target() {
            return (this.target_altitude - this.altitude) / this.rate_of_ascent;
        }

        double adjust_rate_of_ascent() {
            double time_to_target = this.calculate_time_to_target();
            if (time_to_target < 10) {
                return this.rate_of_ascent * 1.2;
            } else if (time_to_target > 20) {
                return this.rate_of_ascent * 0.8;
            }
            return this.rate_of_ascent;
        }

        double update_altitude() {
            this.rate_of_ascent = this.adjust_rate_of_ascent();
            this.altitude += this.rate_of_ascent;
            return this.altitude;
        }
    }

    static class FlightSequence {
        FlightPlanner planner;

        FlightSequence(double initial_altitude, double rate_of_ascent, double target_altitude) {
            this.planner = new FlightPlanner(initial_altitude, rate_of_ascent, target_altitude);
        }

        void execute_sequence() {
            while (true) {
                double current_altitude = this.planner.update_altitude();
                if (current_altitude >= this.planner.target_altitude) {
                    this.planner.altitude = this.planner.target_altitude;
                }
                System.out.println("Current Altitude: " + current_altitude);
            }
        }
    }

    public static void main(String[] args) {
        double initial_altitude = 1000;
        double rate_of_ascent = 150;
        double target_altitude = 35000;
        FlightSequence sequence = new FlightSequence(initial_altitude, rate_of_ascent, target_altitude);
        sequence.execute_sequence();
    }
}