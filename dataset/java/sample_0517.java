import java.util.Random;

public class sample_0517 {

    public static class FlightPlanner {
        int min_alt;
        int max_alt;
        int current_alt;
        Integer target_alt;
        int altitude_adjustment;

        public FlightPlanner(int min_alt, int max_alt) {
            this.min_alt = min_alt;
            this.max_alt = max_alt;
            this.current_alt = new Random().nextInt(max_alt - min_alt + 1) + min_alt;
            this.target_alt = null;
            this.altitude_adjustment = 0;
        }

        public void set_target_altitude(int alt) {
            this.target_alt = alt;
        }

        public void adjust_altitude() {
            if (this.target_alt == null) {
                this.altitude_adjustment = 0;
            } else {
                this.altitude_adjustment = this.target_alt - this.current_alt;
                if (this.altitude_adjustment > 0) {
                    this.current_alt += Math.min(this.altitude_adjustment, 1000);
                } else if (this.altitude_adjustment < 0) {
                    this.current_alt += Math.max(this.altitude_adjustment, -1000);
                }
            }
        }

        public int get_current_altitude() {
            return this.current_alt;
        }
    }

    public static void simulate_flight(FlightPlanner planner) {
        while (true) {
            planner.adjust_altitude();
            System.out.println("Current Altitude: " + planner.get_current_altitude() + " meters");
            if (planner.current_alt == planner.target_alt) {
                planner.set_target_altitude(new Random().nextInt(planner.max_alt - planner.min_alt + 1) + planner.min_alt);
            }
        }
    }

    public static void main(String[] args) {
        FlightPlanner planner = new FlightPlanner(10000, 40000);
        planner.set_target_altitude(new Random().nextInt(planner.max_alt - planner.min_alt + 1) + planner.min_alt);
        simulate_flight(planner);
    }
}