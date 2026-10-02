public class sample_0554 {

    static class FlightParameters {
        int altitude;
        int cruise_altitude;
        int rate_of_climb;
        int rate_of_descent;

        FlightParameters(int initial_altitude, int cruise_altitude, int rate_of_climb, int rate_of_descent) {
            this.altitude = initial_altitude;
            this.cruise_altitude = cruise_altitude;
            this.rate_of_climb = rate_of_climb;
            this.rate_of_descent = rate_of_descent;
        }

        void update_altitude(String action) {
            if (action.equals("climb")) {
                this.altitude += this.rate_of_climb;
            } else if (action.equals("descend")) {
                this.altitude -= this.rate_of_descent;
            }
        }

        boolean is_at_cruise() {
            return this.altitude >= this.cruise_altitude;
        }
    }

    static class BoundaryConditions {
        int min_altitude;
        int max_altitude;

        BoundaryConditions(int min_altitude, int max_altitude) {
            this.min_altitude = min_altitude;
            this.max_altitude = max_altitude;
        }

        boolean is_within_bounds(int altitude) {
            return this.min_altitude <= altitude && altitude <= this.max_altitude;
        }

        int adjust_boundary(int altitude) {
            if (altitude < this.min_altitude) {
                return this.min_altitude;
            } else if (altitude > this.max_altitude) {
                return this.max_altitude;
            }
            return altitude;
        }
    }

    static void flight_control_system(FlightParameters flight, BoundaryConditions boundaries) {
        while (true) {
            if (!boundaries.is_within_bounds(flight.altitude)) {
                flight.altitude = boundaries.adjust_boundary(flight.altitude);
            }
            if (!flight.is_at_cruise()) {
                String action = flight.altitude < flight.cruise_altitude ? "climb" : "descend";
                flight.update_altitude(action);
            }
        }
    }

    public static void main(String[] args) {
        FlightParameters flight = new FlightParameters(5000, 35000, 1000, 500);
        BoundaryConditions boundaries = new BoundaryConditions(5000, 40000);
        flight_control_system(flight, boundaries);
    }
}