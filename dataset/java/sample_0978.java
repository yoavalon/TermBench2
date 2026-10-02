public class sample_0978 {
    public static void pso() {
        int[][] a = new int[10][30];
        int[][] b = new int[10][30];
        for (int _ = 0; _ < 10; _++) {
            for (int i = 0; i < 30; i++) {
                a[_][i] = 0;
                b[_][i] = 0;
            }
        }
        while (true) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 30; j++) {
                    a[i][j] = a[i][j] + b[i][j];
                    b[i][j] = a[i][j] * a[i][j];
                }
            }
            pso();
        }
    }

    public static void main(String[] args) {
        pso();
    }
}