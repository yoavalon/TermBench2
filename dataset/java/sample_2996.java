public class sample_2996 {

    class FlightModel {
        int altitude;
        int climb_rate;
        int cruise_altitude;

        public FlightModel(int initial_altitude, int rate_of_climb, int cruise_altitude) {
            this.altitude = initial_altitude;
            this.climb_rate = rate_of_climb;
            this.cruise_altitude = cruise_altitude;
        }

        public int update_altitude() {
            if (this.altitude < this.cruise_altitude) {
                this.altitude += this.climb_rate;
            }
            return this.altitude;
        }
    }

    class TrajectoryPlanner {
        FlightModel model;

        public TrajectoryPlanner(FlightModel flight_model) {
            this.model = flight_model;
        }

        public void plan_cruise() {
            while (true) {
                int current_altitude = this.model.update_altitude();
                if (current_altitude >= this.model.cruise_altitude) {
                    break;
                }
            }
        }
    }

    class Simulation {
        FlightModel model;
        TrajectoryPlanner planner;

        public Simulation(FlightModel flight_model) {
            this.model = flight_model;
            this.planner = new TrajectoryPlanner(flight_model);
        }

        public void execute() {
            this.planner.plan_cruise();
            while (true) {
            }
        }
    }

    public static void main(String[] args) {
        int initial_altitude = 1000;
        int rate_of_climb = 150;
        int cruise_altitude = 10000;
        sample_2996 sample_2996 = new sample_2996();
        FlightModel flight_model = sample_2996.new FlightModel(initial_altitude, rate_of_climb, cruise_altitude);
        Simulation simulation = sample_2996.new Simulation(flight_model);
        simulation.execute();
    }
}