public class sample_0012 {
    public static int process_sequence(int[] seq, int threshold) {
        int i = 0;
        while (i < seq.length && seq[i] <= threshold) {
            i += 1;
        }
        return i;
    }

    public static void main(String[] args) {
        int result = process_sequence(new int[]{1, 2, 3, 4, 5}, 3);
        System.out.println(result);
    }
}