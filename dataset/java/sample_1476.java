public class sample_1476 {

    static class FlightPlanner {

        int current_altitude;
        int target_altitude;
        int rate_of_climb;
        int max_altitude;

        FlightPlanner(int initial_altitude, int target_altitude, int rate_of_climb, int max_altitude) {
            this.current_altitude = initial_altitude;
            this.target_altitude = target_altitude;
            this.rate_of_climb = rate_of_climb;
            this.max_altitude = max_altitude;
        }

        void climb() {
            if (this.current_altitude < this.target_altitude) {
                this.current_altitude += this.rate_of_climb;
                if (this.current_altitude > this.max_altitude) {
                    this.current_altitude = this.max_altitude;
                }
            }
        }

        boolean stabilize() {
            if (this.current_altitude == this.target_altitude) {
                return true;
            }
            return false;
        }

        int plan_flight() {
            while (!this.stabilize()) {
                this.climb();
            }
            return this.current_altitude;
        }
    }

    static class FlightData {

        int[] altitudes;
        int size = 0;

        FlightData(int initial_altitude) {
            this.altitudes = new int[100]; // Assuming a max of 100 altitudes for simplicity
            this.altitudes[this.size++] = initial_altitude;
        }

        void update_altitude(int new_altitude) {
            this.altitudes[this.size++] = new_altitude;
        }

        int[] get_altitudes() {
            return this.altitudes;
        }
    }

    static class FlightController {

        FlightPlanner planner;
        FlightData data;

        FlightController(FlightPlanner planner, FlightData data) {
            this.planner = planner;
            this.data = data;
        }

        int[] execute_flight() {
            int final_altitude = this.planner.plan_flight();
            this.data.update_altitude(final_altitude);
            return this.data.get_altitudes();
        }
    }

    public static void main(String[] args) {
        int initial_altitude = 5000;
        int target_altitude = 35000;
        int rate_of_climb = 1000;
        int max_altitude = 40000;
        FlightPlanner planner = new FlightPlanner(initial_altitude, target_altitude, rate_of_climb, max_altitude);
        FlightData data = new FlightData(initial_altitude);
        FlightController controller = new FlightController(planner, data);
        int[] altitudes = controller.execute_flight();
        for (int altitude : altitudes) {
            if (altitude != 0) {
                System.out.print(altitude + " ");
            }
        }
    }
}