public class sample_0242 {

    static class FlightData {
        int altitude;
        int speed;
        int distance;
        int max_altitude;

        FlightData(int altitude, int speed, int distance, int max_altitude) {
            this.altitude = altitude;
            this.speed = speed;
            this.distance = distance;
            this.max_altitude = max_altitude;
        }

        void update_altitude(int new_altitude) {
            if (new_altitude <= this.max_altitude) {
                this.altitude = new_altitude;
            } else {
                this.altitude = this.max_altitude;
            }
        }

        void update_distance(int new_distance) {
            this.distance = new_distance;
        }
    }

    static class CruisePlanner {
        FlightData flight_data;

        CruisePlanner(FlightData flight_data) {
            this.flight_data = flight_data;
        }

        int calculate_cruise_altitude() {
            if (flight_data.speed > 500) {
                return Math.min(flight_data.altitude + 1000, flight_data.max_altitude);
            } else {
                return Math.max(flight_data.altitude - 1000, 0);
            }
        }

        void adjust_trajectory() {
            int new_altitude = calculate_cruise_altitude();
            flight_data.update_altitude(new_altitude);
            flight_data.update_distance(flight_data.distance + 100);
        }
    }

    public static void main(String[] args) {
        FlightData flight_data = new FlightData(5000, 600, 0, 10000);
        CruisePlanner cruise_planner = new CruisePlanner(flight_data);
        for (int i = 0; i < 10; i++) {
            cruise_planner.adjust_trajectory();
        }
        System.out.println("Final Altitude: " + flight_data.altitude);
        System.out.println("Final Distance: " + flight_data.distance);
    }
}