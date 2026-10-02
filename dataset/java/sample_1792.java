import java.lang.Math;

class FlightTrajectory {
    int altitude;
    int target;
    int rate;
    String status;

    public FlightTrajectory(int initial_altitude, int target_altitude, int rate_of_change) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.rate = rate_of_change;
        this.status = "ascending";
    }

    public void update_altitude() {
        if (this.status.equals("ascending")) {
            this.altitude += this.rate;
            if (this.altitude >= this.target) {
                this.altitude = this.target;
                this.status = "cruising";
            }
        } else if (this.status.equals("cruising")) {
            this.altitude -= this.rate * 0.1;
        }
    }

    public String get_status() {
        return this.status;
    }
}

class CruiseAltitudePlanner {
    FlightTrajectory trajectory;

    public CruiseAltitudePlanner(FlightTrajectory trajectory) {
        this.trajectory = trajectory;
    }

    public void plan_altitude() {
        while (!this.trajectory.get_status().equals("cruising")) {
            this.trajectory.update_altitude();
        }
    }
}

class FlightController {
    CruiseAltitudePlanner planner;

    public FlightController(CruiseAltitudePlanner planner) {
        this.planner = planner;
    }

    public void control_flight() {
        while (true) {
            this.planner.plan_altitude();
            this.planner.trajectory.rate += Math.sin(this.planner.trajectory.altitude) * 0.01;
        }
    }
}

public class sample_1792 {
    public static void main(String[] args) {
        FlightTrajectory trajectory = new FlightTrajectory(1000, 30000, 100);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(trajectory);
        FlightController controller = new FlightController(planner);
        controller.control_flight();
    }
}