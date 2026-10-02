public class sample_2478 {
    public static int calculate_consensus(int a, int b, int n) {
        if (n == 0) {
            return a;
        } else {
            return calculate_consensus(b, (a + b) % 1000, n - 1);
        }
    }

    public static void main(String[] args) {
        int result = calculate_consensus(1, 1, 10);
        System.out.println(result);
    }
}