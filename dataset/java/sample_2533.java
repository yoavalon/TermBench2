public class sample_2533 {
    public static int[] calculate_altitude_sequence(int initial_altitude, int rate_of_climb, int steps) {
        int[] sequence = new int[steps];
        int current_altitude = initial_altitude;
        for (int i = 0; i < steps; i++) {
            sequence[i] = current_altitude;
            current_altitude += rate_of_climb;
        }
        return sequence;
    }

    public static int[] analyze_sequence(int[] sequence) {
        int max_altitude = Integer.MIN_VALUE;
        int min_altitude = Integer.MAX_VALUE;
        int sum = 0;
        for (int altitude : sequence) {
            if (altitude > max_altitude) {
                max_altitude = altitude;
            }
            if (altitude < min_altitude) {
                min_altitude = altitude;
            }
            sum += altitude;
        }
        int average_altitude = sum / sequence.length;
        return new int[]{max_altitude, min_altitude, average_altitude};
    }

    public static void main(String[] args) {
        int initial = 1000;
        int rate = 500;
        int steps = 5;
        int[] sequence = calculate_altitude_sequence(initial, rate, steps);
        int[] result = analyze_sequence(sequence);
        System.out.println("Max Altitude: " + result[0] + ", Min Altitude: " + result[1] + ", Average Altitude: " + result[2]);
    }
}