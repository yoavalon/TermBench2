public class sample_2494 {
    public static int[] analyze_sequence(int n) {
        int a = 0, b = 1;
        int[] sequence = new int[n];
        for (int i = 0; i < n; i++) {
            sequence[i] = a;
            int temp = a;
            a = b;
            b = temp + b;
        }
        return sequence;
    }

    public static void main(String[] args) {
        int[] result = analyze_sequence(10);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}