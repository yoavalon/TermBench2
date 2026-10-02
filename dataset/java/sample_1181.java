public class sample_1181 {

    static class FlightPlanner {
        int altitude;
        int speed;
        int target_altitude;

        FlightPlanner(int altitude, int speed, int target_altitude) {
            this.altitude = altitude;
            this.speed = speed;
            this.target_altitude = target_altitude;
        }

        void adjust_altitude() {
            if (this.altitude < this.target_altitude) {
                this.altitude += this.speed;
                this.adjust_altitude();
            } else if (this.altitude > this.target_altitude) {
                this.altitude -= this.speed;
                this.adjust_altitude();
            }
        }
    }

    static class TrajectorySimulator {
        int altitude;
        int speed;

        TrajectorySimulator(int altitude, int speed) {
            this.altitude = altitude;
            this.speed = speed;
        }

        void simulate() {
            this.altitude += this.speed;
            this.simulate();
        }
    }

    static class CruiseControl {
        int altitude;
        int target_altitude;

        CruiseControl(int altitude, int target_altitude) {
            this.altitude = altitude;
            this.target_altitude = target_altitude;
        }

        void control() {
            if (this.altitude != this.target_altitude) {
                this.altitude += this.altitude < this.target_altitude ? 1 : -1;
                this.control();
            }
        }
    }

    public static void main(String[] args) {
        FlightPlanner planner = new FlightPlanner(1000, 50, 30000);
        TrajectorySimulator simulator = new TrajectorySimulator(1000, 100);
        CruiseControl cruise = new CruiseControl(1000, 30000);
        planner.adjust_altitude();
        simulator.simulate();
        cruise.control();
    }
}