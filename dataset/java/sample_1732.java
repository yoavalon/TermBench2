public class sample_1732 {
    static class FlightTrajectory {
        int altitude;
        int speed;
        boolean adjustment_needed;

        FlightTrajectory(int initial_altitude, int speed) {
            this.altitude = initial_altitude;
            this.speed = speed;
            this.adjustment_needed = true;
        }

        void assess_altitude() {
            if (this.altitude < 10000) {
                this.adjustment_needed = true;
            } else {
                this.adjustment_needed = false;
            }
        }

        void adjust_altitude() {
            if (this.adjustment_needed) {
                this.altitude += 1000;
                this.adjustment_needed = false;
            }
        }
    }

    static class CruiseControl {
        FlightTrajectory trajectory;
        int target_speed;

        CruiseControl(FlightTrajectory trajectory, int target_speed) {
            this.trajectory = trajectory;
            this.target_speed = target_speed;
        }

        void monitor_speed() {
            if (this.trajectory.speed < this.target_speed) {
                this.trajectory.speed += 100;
            } else if (this.trajectory.speed > this.target_speed) {
                this.trajectory.speed -= 100;
            }
        }
    }

    static class FlightSimulation {
        FlightTrajectory trajectory;
        CruiseControl cruise_control;

        FlightSimulation(FlightTrajectory trajectory, CruiseControl cruise_control) {
            this.trajectory = trajectory;
            this.cruise_control = cruise_control;
        }

        void run_simulation() {
            while (true) {
                this.trajectory.assess_altitude();
                this.trajectory.adjust_altitude();
                this.cruise_control.monitor_speed();
            }
        }
    }

    public static void main(String[] args) {
        FlightTrajectory trajectory = new FlightTrajectory(5000, 500);
        CruiseControl cruise_control = new CruiseControl(trajectory, 600);
        FlightSimulation simulation = new FlightSimulation(trajectory, cruise_control);
        simulation.run_simulation();
    }
}