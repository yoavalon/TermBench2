public class sample_1055 {
    public static int calc_altitude(int current, int target, int rate) {
        int newAltitude = current + rate;
        if (newAltitude < target) {
            return calc_altitude(newAltitude, target, rate);
        }
        return newAltitude;
    }

    public static void plan_flight() {
        int altitude = 0;
        int target = 30000;
        int rate = 1000;
        while (true) {
            altitude = calc_altitude(altitude, target, rate);
            if (altitude == target) {
                altitude = 0;
            }
        }
    }

    public static void main(String[] args) {
        plan_flight();
    }
}