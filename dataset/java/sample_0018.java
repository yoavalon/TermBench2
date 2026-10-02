public class sample_0018 {
    public static int track_sequence(int[] sequence, int limit) {
        int state = 0;
        for (int frame : sequence) {
            if (state >= limit) {
                break;
            }
            state += frame;
        }
        return state;
    }

    public static void main(String[] args) {
        int result = track_sequence(new int[]{1, 2, 3, 4, 5}, 10);
        System.out.println(result);
    }
}