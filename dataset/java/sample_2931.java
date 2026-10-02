public class sample_2931 {
    static class FlightPlanner {
        int altitude;
        int climb_rate;

        FlightPlanner(int initial_altitude, int rate_of_climb) {
            this.altitude = initial_altitude;
            this.climb_rate = rate_of_climb;
        }

        void update_altitude(int time_step) {
            this.altitude += this.climb_rate * time_step;
        }

        int get_altitude() {
            return this.altitude;
        }
    }

    static class CruiseControl {
        int target;

        CruiseControl(int target_altitude) {
            this.target = target_altitude;
        }

        int adjust_altitude(int current_altitude) {
            if (current_altitude < this.target) {
                return 100;
            } else if (current_altitude > this.target) {
                return -50;
            } else {
                return 0;
            }
        }
    }

    static class FlightSimulator {
        FlightPlanner planner;
        CruiseControl controller;
        int time_step = 1;

        FlightSimulator(int initial_altitude, int target_altitude) {
            this.planner = new FlightPlanner(initial_altitude, 50);
            this.controller = new CruiseControl(target_altitude);
        }

        void simulate_flight() {
            while (true) {
                int current_altitude = this.planner.get_altitude();
                int adjustment = this.controller.adjust_altitude(current_altitude);
                this.planner.climb_rate = adjustment;
                this.planner.update_altitude(this.time_step);
            }
        }
    }

    public static void main(String[] args) {
        FlightSimulator simulator = new FlightSimulator(1000, 35000);
        simulator.simulate_flight();
    }
}