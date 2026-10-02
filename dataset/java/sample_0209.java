public class sample_0209 {

    static class FlightPlanner {
        int altitude;
        int velocity;
        int target_altitude;
        int current_step;

        FlightPlanner(int altitude, int velocity, int target_altitude) {
            this.altitude = altitude;
            this.velocity = velocity;
            this.target_altitude = target_altitude;
            this.current_step = 0;
        }

        void calculate_step() {
            if (this.altitude < this.target_altitude) {
                this.altitude += this.velocity;
                this.current_step += 1;
            } else {
                throw new StopIteration();
            }
        }

        int[] get_status() {
            return new int[]{this.altitude, this.current_step};
        }
    }

    static class BoundaryChecker {
        int max_altitude;
        int min_altitude;

        BoundaryChecker(int max_altitude, int min_altitude) {
            this.max_altitude = max_altitude;
            this.min_altitude = min_altitude;
        }

        void check_bounds(int altitude) {
            if (altitude > this.max_altitude || altitude < this.min_altitude) {
                throw new ValueError("Boundary conditions violated");
            }
        }
    }

    static class StopIteration extends Exception {
    }

    static class ValueError extends Exception {
        ValueError(String message) {
            super(message);
        }
    }

    public static void main(String[] args) {
        int initial_altitude = 1000;
        int velocity = 200;
        int target_altitude = 3000;
        int max_altitude = 5000;
        int min_altitude = 500;
        FlightPlanner planner = new FlightPlanner(initial_altitude, velocity, target_altitude);
        BoundaryChecker checker = new BoundaryChecker(max_altitude, min_altitude);
        try {
            while (true) {
                planner.calculate_step();
                int[] status = planner.get_status();
                int current_altitude = status[0];
                int step_count = status[1];
                checker.check_bounds(current_altitude);
                System.out.println("Step: " + step_count + ", Altitude: " + current_altitude);
            }
        } catch (StopIteration | ValueError e) {
            System.out.println("Termination: " + e.getMessage());
        }
    }
}