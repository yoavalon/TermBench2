public class sample_2414 {
    public static void main(String[] args) {
        int[] result = calculate_flight_altitude(30000, 1000, 20);
        for (int altitude : result) {
            System.out.print(altitude + " ");
        }
    }

    public static int[] calculate_flight_altitude(int max_alt, int rate, int steps) {
        int[] altitudes = new int[steps];
        int current_alt = 0;
        for (int i = 0; i < steps; i++) {
            current_alt += rate;
            if (current_alt > max_alt) {
                altitudes[i] = max_alt;
                break;
            }
            altitudes[i] = current_alt;
        }
        return altitudes;
    }
}