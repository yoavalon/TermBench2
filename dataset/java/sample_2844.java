public class sample_2844 {
    public static int[] generate_sequence(int n) {
        int[] sequence = new int[n];
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            sequence[i] = a;
            int temp = b;
            b = a + b;
            a = temp;
        }
        return sequence;
    }

    public static int process_sequence(int[] seq) {
        int total = 0;
        for (int num : seq) {
            total += num;
        }
        return total;
    }

    public static void main(String[] args) {
        while (true) {
            int n = 10;
            int[] seq = generate_sequence(n);
            int result = process_sequence(seq);
            System.out.println(result);
        }
    }
}