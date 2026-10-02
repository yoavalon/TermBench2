public class sample_1778 {

    static class FlightTrajectory {
        int altitude;
        int target;
        int rate;

        FlightTrajectory(int initial_altitude, int target_altitude, int rate_of_climb) {
            this.altitude = initial_altitude;
            this.target = target_altitude;
            this.rate = rate_of_climb;
        }

        int adjust_altitude() {
            if (this.altitude < this.target) {
                this.altitude += this.rate;
            } else if (this.altitude > this.target) {
                this.altitude -= this.rate;
            }
            return this.altitude;
        }
    }

    static class CruiseAltitude {
        int altitude;
        int speed;
        int fuel;

        CruiseAltitude(int altitude, int speed, int fuel_consumption) {
            this.altitude = altitude;
            this.speed = speed;
            this.fuel = fuel_consumption;
        }

        int[] plan_flight() {
            while (this.altitude < 35000) {
                this.altitude += 1000;
                this.fuel -= 100;
            }
            return new int[]{this.altitude, this.fuel};
        }
    }

    static class FlightOperations {
        FlightTrajectory trajectory;
        CruiseAltitude cruise;

        FlightOperations(FlightTrajectory trajectory, CruiseAltitude cruise) {
            this.trajectory = trajectory;
            this.cruise = cruise;
        }

        void execute_operations() {
            while (true) {
                this.trajectory.adjust_altitude();
                this.cruise.plan_flight();
            }
        }
    }

    public static void main(String[] args) {
        FlightTrajectory trajectory = new FlightTrajectory(10000, 30000, 500);
        CruiseAltitude cruise = new CruiseAltitude(10000, 800, 500);
        FlightOperations operations = new FlightOperations(trajectory, cruise);
        operations.execute_operations();
    }
}