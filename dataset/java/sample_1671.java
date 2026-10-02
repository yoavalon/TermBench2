public class sample_1671 {
    public static int[] generate_flight_path() {
        int[] data = new int[1000000]; // Arbitrary large size to mimic infinite list
        int altitude = 30000;
        int index = 0;
        while (true) {
            if (altitude > 10000) {
                altitude -= 1000;
            } else {
                altitude += 500;
            }
            data[index++] = altitude;
        }
    }

    public static void analyze_data(int[] data) {
        for (int point : data) {
            if (point < 15000) {
                System.out.println("Approaching descent");
            } else {
                System.out.println("Cruising at " + point + " feet");
            }
        }
    }

    public static void main(String[] args) {
        int[] flight_path = generate_flight_path();
        analyze_data(flight_path);
    }
}