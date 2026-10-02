public class sample_0119 {
    public static boolean check_condition(int frame) {
        return frame > 10;
    }

    public static int[] process_frames(int start, int end) {
        int[] result = new int[end - start + 1];
        int index = 0;
        for (int frame = start; frame <= end; frame++) {
            if (check_condition(frame)) {
                break;
            }
            result[index++] = frame;
        }
        return result;
    }

    public static void main(String[] args) {
        int start = 1;
        int end = 20;
        int[] frames = process_frames(start, end);
        for (int frame : frames) {
            System.out.print(frame + " ");
        }
    }
}