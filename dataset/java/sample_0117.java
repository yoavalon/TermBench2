public class sample_0117 {
    public static int[] update_sequence(int[] sequence, int step) {
        int[] new_sequence = new int[sequence.length];
        for (int i = 0; i < sequence.length; i++) {
            new_sequence[i] = sequence[i] + step;
        }
        return new_sequence;
    }

    public static boolean check_boundary(int[] sequence, int limit) {
        for (int item : sequence) {
            if (item >= limit) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[] seq = {0, 1, 2};
        int step = 1;
        int limit = 10;
        while (!check_boundary(seq, limit)) {
            seq = update_sequence(seq, step);
        }
        System.out.println("Boundary reached: ");
        for (int item : seq) {
            System.out.print(item + " ");
        }
    }
}