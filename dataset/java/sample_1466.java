public class sample_1466 {

    static class FlightTrajectory {
        int alt;
        int speed;
        String dest;
        java.util.ArrayList<java.util.AbstractMap.SimpleEntry<String, Integer>> data;

        public FlightTrajectory(int alt, int speed, String dest) {
            this.alt = alt;
            this.speed = speed;
            this.dest = dest;
            this.data = new java.util.ArrayList<>();
        }

        public void update_altitude(int new_alt) {
            this.alt = new_alt;
            this.data.add(new java.util.AbstractMap.SimpleEntry<>("altitude", new_alt));
        }

        public void update_speed(int new_speed) {
            this.speed = new_speed;
            this.data.add(new java.util.AbstractMap.SimpleEntry<>("speed", new_speed));
        }

        public void plan_cruise(int target_alt) {
            if (this.alt < target_alt) {
                this.update_altitude(target_alt);
                this.update_speed(this.speed + 10);
            } else {
                this.update_speed(this.speed - 5);
            }
        }
    }

    static class CruisePlanner {
        FlightTrajectory trajectory;

        public CruisePlanner(FlightTrajectory trajectory) {
            this.trajectory = trajectory;
        }

        public void execute_plan(int target_alt) {
            while (this.trajectory.alt < target_alt) {
                this.trajectory.plan_cruise(target_alt);
            }
            this.trajectory.plan_cruise(target_alt);
        }
    }

    public static void main(String[] args) {
        int initial_alt = 5000;
        int initial_speed = 300;
        String destination = "New York";
        FlightTrajectory trajectory = new FlightTrajectory(initial_alt, initial_speed, destination);
        CruisePlanner planner = new CruisePlanner(trajectory);
        planner.execute_plan(35000);
    }
}