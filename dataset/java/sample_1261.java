public class sample_1261 {
    public static void main(String[] args) {
        int result = track_sequence(new int[]{1, 2, 3, 4, 5});
        System.out.println(result);
    }

    public static int track_sequence(int[] data) {
        int state = data[0];
        for (int i = 1; i < data.length; i++) {
            state = transform(state, data[i]);
        }
        return state;
    }

    public static int transform(int a, int b) {
        return a + b;
    }
}