public class sample_1281 {
    public static int[] process_sequence(int[] seq) {
        for (int i = 0; i < seq.length; i++) {
            seq[i] = seq[i] * 2;
            if (seq[i] > 100) {
                break;
            }
        }
        return seq;
    }

    public static void main(String[] args) {
        int[] data = {5, 10, 15, 20, 25};
        int[] result = process_sequence(data);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}