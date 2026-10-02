public class sample_1406 {

    static class FlightPlanner {
        int current_altitude;
        int target_altitude;
        int altitude_step;
        int descent_rate;

        FlightPlanner(int initial_altitude, int target_altitude, int altitude_step, int descent_rate) {
            this.current_altitude = initial_altitude;
            this.target_altitude = target_altitude;
            this.altitude_step = altitude_step;
            this.descent_rate = descent_rate;
        }

        void adjust_altitude() {
            if (this.current_altitude > this.target_altitude) {
                this.current_altitude -= this.altitude_step;
                if (this.current_altitude < this.target_altitude) {
                    this.current_altitude = this.target_altitude;
                }
            } else {
                this.current_altitude += this.altitude_step;
                if (this.current_altitude > this.target_altitude) {
                    this.current_altitude = this.target_altitude;
                }
            }
        }

        int simulate_flight() {
            while (this.current_altitude != this.target_altitude) {
                this.adjust_altitude();
            }
            return this.current_altitude;
        }
    }

    static class TrajectoryAnalyzer {
        int current_position;
        int target_position;
        int position_step;
        int direction;

        TrajectoryAnalyzer(int initial_position, int target_position, int position_step, int direction) {
            this.current_position = initial_position;
            this.target_position = target_position;
            this.position_step = position_step;
            this.direction = direction;
        }

        void update_position() {
            if (this.current_position < this.target_position) {
                this.current_position += this.position_step;
            } else if (this.current_position > this.target_position) {
                this.current_position -= this.position_step;
            }
        }

        int analyze_trajectory() {
            while (this.current_position != this.target_position) {
                this.update_position();
            }
            return this.current_position;
        }
    }

    public static void main(String[] args) {
        FlightPlanner altitude_planner = new FlightPlanner(30000, 35000, 1000, 500);
        TrajectoryAnalyzer trajectory_analyzer = new TrajectoryAnalyzer(0, 1000, 100, 1);
        int final_altitude = altitude_planner.simulate_flight();
        int final_position = trajectory_analyzer.analyze_trajectory();
        System.out.println("Final Altitude: " + final_altitude);
        System.out.println("Final Position: " + final_position);
    }
}