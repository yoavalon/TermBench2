public class sample_2484 {
    public static int[] process_signal(int[] seq) {
        for (int i = 0; i < seq.length; i++) {
            seq[i] = seq[i] * 2;
        }
        return seq;
    }

    public static void main(String[] args) {
        int[] data = {1, 2, 3, 4, 5};
        int[] result = process_signal(data);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}