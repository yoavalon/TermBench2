import java.lang.Math;

class FlightModel {
    double altitude;
    double rate_of_climb;
    double max_altitude;

    FlightModel(double initial_altitude, double rate_of_climb, double max_altitude) {
        this.altitude = initial_altitude;
        this.rate_of_climb = rate_of_climb;
        this.max_altitude = max_altitude;
    }

    void update_altitude() {
        this.altitude += this.rate_of_climb;
        if (this.altitude > this.max_altitude) {
            this.altitude = this.max_altitude;
        }
    }
}

class TrajectoryPlanner {
    FlightModel model;
    double cruise_altitude;
    double target_distance;
    double speed;

    TrajectoryPlanner(FlightModel model, double cruise_altitude, double target_distance, double speed) {
        this.model = model;
        this.cruise_altitude = cruise_altitude;
        this.target_distance = target_distance;
        this.speed = speed;
    }

    double calculate_time_to_cruise() {
        return (this.cruise_altitude - this.model.altitude) / this.model.rate_of_climb;
    }

    double calculate_time_to_target() {
        double time_to_cruise = this.calculate_time_to_cruise();
        double time_in_cruise = this.target_distance / this.speed;
        return time_to_cruise + time_in_cruise;
    }
}

class Simulation {
    FlightModel model;
    TrajectoryPlanner planner;

    Simulation(FlightModel model, TrajectoryPlanner planner) {
        this.model = model;
        this.planner = planner;
    }

    void run() {
        while (true) {
            this.model.update_altitude();
            if (this.model.altitude >= this.planner.cruise_altitude) {
                this.planner.cruise_altitude = Double.POSITIVE_INFINITY;
            }
            System.out.println("Current Altitude: " + this.model.altitude + ", Time to Target: " + this.planner.calculate_time_to_target());
        }
    }
}

public class sample_2958 {
    public static void main(String[] args) {
        FlightModel flight_model = new FlightModel(1000, 500, 30000);
        TrajectoryPlanner trajectory_planner = new TrajectoryPlanner(flight_model, 20000, 1000, 500);
        Simulation simulation = new Simulation(flight_model, trajectory_planner);
        simulation.run();
    }
}