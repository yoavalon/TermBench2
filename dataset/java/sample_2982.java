import java.math.*;

class FlightTrajectory {
    int altitude;
    int rate_of_climb;
    int cruise_altitude;
    int descent_rate;
    String status;

    FlightTrajectory(int initial_altitude, int rate_of_climb, int cruise_altitude, int descent_rate) {
        this.altitude = initial_altitude;
        this.rate_of_climb = rate_of_climb;
        this.cruise_altitude = cruise_altitude;
        this.descent_rate = descent_rate;
        this.status = "climbing";
    }

    void update_altitude() {
        if (this.status.equals("climbing")) {
            if (this.altitude + this.rate_of_climb < this.cruise_altitude) {
                this.altitude += this.rate_of_climb;
            } else {
                this.altitude = this.cruise_altitude;
                this.status = "cruising";
            }
        } else if (this.status.equals("cruising")) {
        } else if (this.status.equals("descending")) {
            if (this.altitude - this.descent_rate > 0) {
                this.altitude -= this.descent_rate;
            } else {
                this.altitude = 0;
                this.status = "landed";
            }
        }
    }

    boolean is_landed() {
        return this.status.equals("landed");
    }
}

class FlightPlanner {
    FlightTrajectory trajectory;

    FlightPlanner(FlightTrajectory trajectory) {
        this.trajectory = trajectory;
    }

    void plan_flight() {
        while (!this.trajectory.is_landed()) {
            this.trajectory.update_altitude();
            this.log_status();
        }
    }

    void log_status() {
        System.out.println("Altitude: " + this.trajectory.altitude + ", Status: " + this.trajectory.status);
    }
}

public class sample_2982 {
    public static void main(String[] args) {
        int initial_altitude = 0;
        int rate_of_climb = 1000;
        int cruise_altitude = 30000;
        int descent_rate = 500;
        FlightTrajectory trajectory = new FlightTrajectory(initial_altitude, rate_of_climb, cruise_altitude, descent_rate);
        FlightPlanner planner = new FlightPlanner(trajectory);
        planner.plan_flight();
    }
}