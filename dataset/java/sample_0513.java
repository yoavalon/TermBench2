public class sample_0513 {

    static class FlightPath {
        int altitude;
        int target_altitude;
        int rate_of_climb;

        FlightPath(int start_altitude, int target_altitude, int rate_of_climb) {
            this.altitude = start_altitude;
            this.target_altitude = target_altitude;
            this.rate_of_climb = rate_of_climb;
        }

        void climb() {
            this.altitude += this.rate_of_climb;
            if (this.altitude > this.target_altitude) {
                this.altitude = this.target_altitude;
            }
        }

        int[] get_status() {
            return new int[]{this.altitude, this.target_altitude};
        }
    }

    static class CruiseAltitude {
        int altitude;
        int max_speed;
        int wind_speed;

        CruiseAltitude(int altitude, int max_speed, int wind_speed) {
            this.altitude = altitude;
            this.max_speed = max_speed;
            this.wind_speed = wind_speed;
        }

        void adjust_speed() {
            this.max_speed = this.max_speed - this.wind_speed * 0.5;
        }

        int get_speed() {
            return this.max_speed;
        }
    }

    public static void main(String[] args) {
        FlightPath flight = new FlightPath(1000, 35000, 100);
        CruiseAltitude cruise = new CruiseAltitude(35000, 800, 20);
        while (true) {
            flight.climb();
            cruise.adjust_speed();
            int[] status = flight.get_status();
            int current_alt = status[0];
            int target_alt = status[1];
            int current_speed = cruise.get_speed();
            if (current_alt == target_alt) {
                System.out.println("Reached target altitude: " + current_alt);
                System.out.println("Cruise speed adjusted to: " + current_speed);
            } else {
                System.out.println("Current altitude: " + current_alt + ", Target altitude: " + target_alt);
                System.out.println("Current speed: " + current_speed);
            }
        }
    }
}