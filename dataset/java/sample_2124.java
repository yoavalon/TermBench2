public class sample_2124 {
    public static void cellular_automata(int n) {
        int[][] a = new int[n][n];
        while (true) {
            int[][] b = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    b[i][j] = (a[i][j] + a[(i - 1 + n) % n][j] + a[i][(j - 1 + n) % n] + a[(i + 1) % n][j] + a[i][(j + 1) % n]) / 5;
                }
            }
            a = b;
        }
    }

    public static void main(String[] args) {
        cellular_automata(10);
    }
}