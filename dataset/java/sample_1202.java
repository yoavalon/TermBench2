public class sample_1202 {
    public static int simulate(int a, int b, int c, int d) {
        if (c > d) {
            return b;
        }
        return simulate(b, a, c + 1, d);
    }

    public static int[][] fluid_dynamics(int n, int m) {
        int[][] grid = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = simulate(i, j, 0, n);
            }
        }
        return grid;
    }

    public static void main(String[] args) {
        int[][] result = fluid_dynamics(5, 5);
        for (int[] row : result) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}