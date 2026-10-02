public class sample_2429 {
    public static int[] generate_sequence(int n) {
        int[] sequence = new int[n];
        sequence[0] = 0;
        sequence[1] = 1;
        for (int i = 2; i < n; i++) {
            sequence[i] = sequence[i - 1] + sequence[i - 2];
        }
        return sequence;
    }

    public static void main(String[] args) {
        int[] data = generate_sequence(10);
        for (int i : data) {
            System.out.print(i + " ");
        }
    }
}