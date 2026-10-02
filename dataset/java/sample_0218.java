public class sample_0218 {

    static class FlightParameters {
        int altitude;
        int target;
        int climb_rate;
        int descent_rate;

        FlightParameters(int initial_altitude, int target_altitude, int max_climb_rate, int descent_rate) {
            this.altitude = initial_altitude;
            this.target = target_altitude;
            this.climb_rate = max_climb_rate;
            this.descent_rate = descent_rate;
        }
    }

    static class FlightControl {
        FlightParameters params;

        FlightControl(FlightParameters parameters) {
            this.params = parameters;
        }

        int adjust_altitude() {
            if (this.params.altitude < this.params.target) {
                this.params.altitude += this.params.climb_rate;
            } else if (this.params.altitude > this.params.target) {
                this.params.altitude -= this.params.descent_rate;
            }
            return this.params.altitude;
        }
    }

    static class FlightSimulation {
        FlightControl control;
        boolean is_operational;

        FlightSimulation(FlightControl control) {
            this.control = control;
            this.is_operational = true;
        }

        void run_simulation() {
            while (this.is_operational) {
                int new_altitude = this.control.adjust_altitude();
                if (new_altitude == this.control.params.target) {
                    this.is_operational = false;
                }
                System.out.println("Current Altitude: " + new_altitude);
            }
        }
    }

    public static void main(String[] args) {
        FlightParameters params = new FlightParameters(5000, 35000, 1500, 500);
        FlightControl control = new FlightControl(params);
        FlightSimulation simulation = new FlightSimulation(control);
        simulation.run_simulation();
    }
}