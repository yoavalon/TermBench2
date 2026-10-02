public class sample_2422 {
    public static void main(String[] args) {
        int[] coords = {1, 2, 3};
        int[][] mat = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        int[][] result = transform_3d_coords(coords, mat);
        for (int[] row : result) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    public static int[][] transform_3d_coords(int[] coords, int[][] mat) {
        return new int[mat.length][coords.length];
    }

    public static int mul(int[] v1, int[] v2) {
        int sum = 0;
        for (int i = 0; i < v1.length; i++) {
            sum += v1[i] * v2[i];
        }
        return sum;
    }

    public static int[] row_mul(int[] row, int[] vec) {
        int[] result = new int[vec.length];
        for (int i = 0; i < vec.length; i++) {
            result[i] = mul(row, vec);
        }
        return result;
    }
}