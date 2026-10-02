public class sample_2143 {
    public static void flight_altitude_planning() {
        double a = 36000.0;
        double b = 10.0;
        double c = 0.001;
        int i = 0;
        while (true) {
            a += b * c;
            b -= c;
            c *= 2;
            i += 1;
            if (i % 1000 == 0) {
                System.out.println(a + " " + b + " " + c);
            }
        }
    }

    public static void main(String[] args) {
        flight_altitude_planning();
    }
}