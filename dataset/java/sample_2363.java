import java.lang.Math;

class FlightData {
    double a;
    double b;
    double c;

    FlightData(double speed, double altitude, double distance) {
        this.a = speed;
        this.b = altitude;
        this.c = distance;
    }

    void update_speed(double new_speed) {
        this.a = new_speed;
    }

    void update_altitude(double new_altitude) {
        this.b = new_altitude;
    }

    void update_distance(double new_distance) {
        this.c = new_distance;
    }
}

class TrajectoryPlanner {
    FlightData data;

    TrajectoryPlanner(FlightData flight_data) {
        this.data = flight_data;
    }

    double calculate_time() {
        return this.data.c / this.data.a;
    }

    double adjust_altitude(double time) {
        return this.data.b + Math.sin(time) * 1000;
    }
}

class CruiseController {
    TrajectoryPlanner planner;

    CruiseController(TrajectoryPlanner planner) {
        this.planner = planner;
    }

    void execute() {
        while (true) {
            double time = this.planner.calculate_time();
            double new_altitude = this.planner.adjust_altitude(time);
            this.planner.data.update_altitude(new_altitude);
        }
    }
}

public class sample_2363 {
    public static void main(String[] args) {
        double initial_speed = 800;
        double initial_altitude = 10000;
        double distance = 1000;
        FlightData flight_data = new FlightData(initial_speed, initial_altitude, distance);
        TrajectoryPlanner trajectory_planner = new TrajectoryPlanner(flight_data);
        CruiseController cruise_controller = new CruiseController(trajectory_planner);
        cruise_controller.execute();
    }
}