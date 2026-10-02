public class sample_2059 {

    static class FlightPlanner {
        double altitude;
        double target;
        double speed;
        double descent;
        int time;

        FlightPlanner(double initial_altitude, double target_altitude, double speed, double descent_rate) {
            this.altitude = initial_altitude;
            this.target = target_altitude;
            this.speed = speed;
            this.descent = descent_rate;
            this.time = 0;
        }

        void update_altitude() {
            if (this.altitude > this.target) {
                this.altitude -= this.descent * this.speed;
                this.time += 1;
            } else {
                this.altitude = this.target;
            }
        }

        double[] get_flight_data() {
            return new double[]{this.altitude, this.time};
        }
    }

    static class TrajectoryAnalyzer {
        FlightPlanner planner;

        TrajectoryAnalyzer(FlightPlanner planner) {
            this.planner = planner;
        }

        double[][] analyze() {
            double[][] data = new double[1000][2]; // Assuming a maximum of 1000 data points
            int index = 0;
            while (this.planner.altitude > this.planner.target) {
                this.planner.update_altitude();
                data[index] = this.planner.get_flight_data();
                index++;
            }
            return data;
        }
    }

    public static void main(String[] args) {
        double initial_altitude = 35000.0;
        double target_altitude = 10000.0;
        double speed = 0.5;
        double descent_rate = 100.0;
        FlightPlanner planner = new FlightPlanner(initial_altitude, target_altitude, speed, descent_rate);
        TrajectoryAnalyzer analyzer = new TrajectoryAnalyzer(planner);
        double[][] trajectory_data = analyzer.analyze();
        for (double[] data : trajectory_data) {
            if (data[0] == target_altitude) {
                break;
            }
            System.out.println("Time: " + (int) data[1] + ", Altitude: " + data[0]);
        }
    }
}