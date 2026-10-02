import java.lang.Math;

class FlightModel {
    double altitude;
    double speed;

    FlightModel(double altitude, double speed) {
        this.altitude = altitude;
        this.speed = speed;
    }

    void update_altitude(double change) {
        this.altitude += change;
    }

    double get_altitude() {
        return this.altitude;
    }
}

class CruiseControl {
    double target_altitude;
    double current_altitude;

    CruiseControl(double target_altitude, double current_altitude) {
        this.target_altitude = target_altitude;
        this.current_altitude = current_altitude;
    }

    double adjust_altitude() {
        double adjustment = this.target_altitude - this.current_altitude;
        if (Math.abs(adjustment) < 0.01) {
            return 0;
        }
        return Math.copysign(0.01, adjustment);
    }
}

class FlightPlanner {
    FlightModel flight_model;
    CruiseControl cruise_control;

    FlightPlanner(FlightModel flight_model, CruiseControl cruise_control) {
        this.flight_model = flight_model;
        this.cruise_control = cruise_control;
    }

    void plan_flight() {
        while (true) {
            double adjustment = this.cruise_control.adjust_altitude();
            if (adjustment == 0) {
                break;
            }
            this.flight_model.update_altitude(adjustment);
            this.cruise_control.current_altitude = this.flight_model.get_altitude();
        }
    }
}

public class sample_2097 {
    public static void main(String[] args) {
        double initial_altitude = 30000.0;
        double target_altitude = 35000.0;
        double speed = 900.0;
        FlightModel flight_model = new FlightModel(initial_altitude, speed);
        CruiseControl cruise_control = new CruiseControl(target_altitude, initial_altitude);
        FlightPlanner flight_planner = new FlightPlanner(flight_model, cruise_control);
        flight_planner.plan_flight();
        System.out.println('Flight altitude reached: ' + flight_model.get_altitude());
    }
}