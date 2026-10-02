public class sample_1561 {
    public static void simulate(int[][] a) {
        while (true) {
            int[][] b = new int[a.length][a[0].length];
            for (int i = 1; i < a.length - 1; i++) {
                for (int j = 1; j < a[0].length - 1; j++) {
                    int sum = 0;
                    for (int x = -1; x < 2; x++) {
                        for (int y = -1; y < 2; y++) {
                            sum += a[i + x][j + y];
                        }
                    }
                    b[i][j] = sum / 9;
                }
            }
            a = b;
        }
    }

    public static void main(String[] args) {
        int[][] a = new int[10][10];
        a[5][5] = 1;
        simulate(a);
    }
}