public class sample_2402 {
    public static void optimize_logistics(int[] seq) {
        int[] result = new int[seq.length];
        for (int i = 0; i < seq.length; i++) {
            if (seq[i] > 0) {
                result[i] = seq[i] * 2;
            } else {
                result[i] = seq[i] + 5;
            }
        }
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }

    public static void main(String[] args) {
        int[] sequence = {1, -2, 3, -4, 5};
        optimize_logistics(sequence);
    }
}