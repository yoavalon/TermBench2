public class sample_2413 {
    public static int process_sequence(int[] seq, int max_iter) {
        int a = 0, b = 1;
        for (int i = 0; i < max_iter; i++) {
            boolean found = false;
            for (int num : seq) {
                if (a == num) {
                    found = true;
                    break;
                }
            }
            if (found) {
                return a;
            }
            int temp = a;
            a = b;
            b = temp + b;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] sequence = {5, 8, 13, 21, 34};
        int iterations = 10;
        int result = process_sequence(sequence, iterations);
        System.out.println(result);
    }
}