import java.util.*;

class FlightPlanner {
    int altitude;
    int speed;

    FlightPlanner(int altitude, int speed) {
        this.altitude = altitude;
        this.speed = speed;
    }

    void update_altitude(int new_altitude) {
        this.altitude = new_altitude;
    }

    double calculate_time_to_descend(int target_altitude) {
        int descent_rate = 1000;
        return (double) (this.altitude - target_altitude) / descent_rate;
    }
}

class CruiseControl {
    int target_speed;

    CruiseControl(int target_speed) {
        this.target_speed = target_speed;
    }

    int adjust_speed(int current_speed) {
        return current_speed != this.target_speed ? this.target_speed : current_speed;
    }
}

class FlightAnalyzer {
    FlightPlanner flight_planner;
    CruiseControl cruise_control;

    FlightAnalyzer(FlightPlanner flight_planner, CruiseControl cruise_control) {
        this.flight_planner = flight_planner;
        this.cruise_control = cruise_control;
    }

    void analyze() {
        while (true) {
            int new_altitude = this.flight_planner.altitude - 100;
            this.flight_planner.update_altitude(new_altitude);
            int adjusted_speed = this.cruise_control.adjust_speed(this.flight_planner.speed);
            System.out.println("Altitude: " + this.flight_planner.altitude + ", Speed: " + adjusted_speed);
        }
    }
}

public class sample_1722 {
    public static void main(String[] args) {
        FlightPlanner planner = new FlightPlanner(10000, 800);
        CruiseControl cruise_control = new CruiseControl(800);
        FlightAnalyzer analyzer = new FlightAnalyzer(planner, cruise_control);
        analyzer.analyze();
    }
}