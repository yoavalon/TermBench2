public class sample_0200 {
    public static boolean track_sequence(int[] sequence, int threshold) {
        int state = 0;
        for (int frame : sequence) {
            if (frame > threshold) {
                state += 1;
            } else {
                state = 0;
            }
            if (state >= 3) {
                return true;
            }
        }
        return false;
    }

    public static boolean analyze_data(int[][] data, int limit) {
        for (int[] item : data) {
            if (track_sequence(item, limit)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[][] data = {{1, 2, 3, 4}, {4, 5, 6, 7}, {7, 8, 9, 10}};
        int limit = 6;
        boolean result = analyze_data(data, limit);
        System.out.println(result);
    }
}