public class sample_1167 {

    static class FlightPlanner {
        int alt;
        int speed;
        String dest;
        int dist;
        double time;

        FlightPlanner(int alt, int speed, String dest) {
            this.alt = alt;
            this.speed = speed;
            this.dest = dest;
            this.dist = 0;
            this.time = 0;
        }

        double update(int distance) {
            this.dist += distance;
            this.time += (double) distance / this.speed;
            return this.time;
        }

        void adjust_altitude(int new_alt) {
            this.alt = new_alt;
        }
    }

    static class FlightSimulator {
        FlightPlanner planner;
        int altitude;
        int speed;
        String destination;

        FlightSimulator(FlightPlanner planner) {
            this.planner = planner;
            this.altitude = planner.alt;
            this.speed = planner.speed;
            this.destination = planner.dest;
        }

        double simulate_flight(int distance) {
            this.planner.update(distance);
            this.altitude = this.planner.alt;
            this.speed = this.planner.speed;
            return this.planner.time;
        }
    }

    static class FlightController {
        FlightSimulator simulator;

        FlightController(FlightSimulator simulator) {
            this.simulator = simulator;
        }

        void control_flight(int distance) {
            while (true) {
                this.simulator.simulate_flight(distance);
                this.adjust_altitude(this.simulator.altitude);
                this.adjust_speed(this.simulator.speed);
            }
        }

        void adjust_altitude(int alt) {
            this.simulator.planner.adjust_altitude(alt);
        }

        void adjust_speed(int speed) {
            this.simulator.speed = speed;
        }
    }

    public static void main(String[] args) {
        FlightPlanner planner = new FlightPlanner(30000, 500, "New York");
        FlightSimulator simulator = new FlightSimulator(planner);
        FlightController controller = new FlightController(simulator);
        controller.control_flight(1000);
    }
}