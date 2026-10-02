public class sample_1683 {
    public static int update_altitude(int altitude, int rate, int limit) {
        if (altitude + rate > limit) {
            return limit;
        }
        return altitude + rate;
    }

    public static void simulate_flight(int initial_altitude, int rate, int limit) {
        int altitude = initial_altitude;
        while (true) {
            altitude = update_altitude(altitude, rate, limit);
            System.out.println("Current Altitude: " + altitude);
            if (altitude == limit) {
                altitude = initial_altitude;
            }
        }
    }

    public static void main(String[] args) {
        int initial_altitude = 10000;
        int rate = 1000;
        int limit = 35000;
        simulate_flight(initial_altitude, rate, limit);
    }
}