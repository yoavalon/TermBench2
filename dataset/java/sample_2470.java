public class sample_2470 {
    public static void main(String[] args) {
        cellular_automata(100);
    }

    public static void cellular_automata(int n) {
        int[] a = new int[n];
        a[n / 2] = 1;
        for (int _ = 0; _ < 10; _++) {
            int[] b = new int[n];
            for (int i = 1; i < n - 1; i++) {
                b[i] = a[i - 1] ^ a[i] ^ a[i + 1];
            }
            a = b;
        }
    }
}