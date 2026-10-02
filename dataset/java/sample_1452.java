import java.util.Arrays;

class FlightTrajectory {
    double altitude;
    double target_altitude;
    double max_altitude;
    double rate_of_climb;
    int time;

    FlightTrajectory(double initial_altitude, double target_altitude, double max_altitude, double rate_of_climb) {
        this.altitude = initial_altitude;
        this.target_altitude = target_altitude;
        this.max_altitude = max_altitude;
        this.rate_of_climb = rate_of_climb;
        this.time = 0;
    }

    void update_altitude() {
        if (this.altitude < this.target_altitude) {
            this.altitude += this.rate_of_climb;
            if (this.altitude > this.max_altitude) {
                this.altitude = this.max_altitude;
            }
        }
        this.time += 1;
    }

    boolean is_complete() {
        return this.altitude >= this.target_altitude;
    }
}

class CruiseAltitudePlanner {
    FlightTrajectory trajectory;

    CruiseAltitudePlanner(FlightTrajectory trajectory) {
        this.trajectory = trajectory;
    }

    double[] plan_cruise() {
        while (!this.trajectory.is_complete()) {
            this.trajectory.update_altitude();
        }
        return new double[]{this.trajectory.altitude, this.trajectory.time};
    }
}

public class sample_1452 {
    public static void main(String[] args) {
        double initial_altitude = 1000;
        double target_altitude = 35000;
        double max_altitude = 40000;
        double rate_of_climb = 1500;
        FlightTrajectory trajectory = new FlightTrajectory(initial_altitude, target_altitude, max_altitude, rate_of_climb);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(trajectory);
        double[] result = planner.plan_cruise();
        System.out.println("Final Altitude: " + result[0] + ", Climb Time: " + result[1]);
    }
}