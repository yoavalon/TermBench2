public class sample_1418 {
    static class FlightData {
        int altitude;
        int speed;
        int heading;

        FlightData(int altitude, int speed, int heading) {
            this.altitude = altitude;
            this.speed = speed;
            this.heading = heading;
        }

        void update_altitude(int new_altitude) {
            this.altitude = new_altitude;
        }

        void update_speed(int new_speed) {
            this.speed = new_speed;
        }

        void update_heading(int new_heading) {
            this.heading = new_heading;
        }
    }

    static int calculate_new_altitude(int current_altitude, int target_altitude, int step) {
        if (current_altitude < target_altitude) {
            return Math.min(current_altitude + step, target_altitude);
        }
        return Math.max(current_altitude - step, target_altitude);
    }

    static int calculate_new_speed(int current_speed, int target_speed, int step) {
        if (current_speed < target_speed) {
            return Math.min(current_speed + step, target_speed);
        }
        return Math.max(current_speed - step, target_speed);
    }

    static void cruise_altitude_planning(FlightData flight, int target_altitude, int target_speed, int step) {
        while (flight.altitude != target_altitude || flight.speed != target_speed) {
            flight.update_altitude(calculate_new_altitude(flight.altitude, target_altitude, step));
            flight.update_speed(calculate_new_speed(flight.speed, target_speed, step));
        }
    }

    public static void main(String[] args) {
        int initial_altitude = 10000;
        int initial_speed = 800;
        int initial_heading = 90;
        int target_altitude = 30000;
        int target_speed = 900;
        int step = 1000;
        FlightData flight = new FlightData(initial_altitude, initial_speed, initial_heading);
        cruise_altitude_planning(flight, target_altitude, target_speed, step);
        System.out.println("Final altitude: " + flight.altitude + ", Final speed: " + flight.speed);
    }
}