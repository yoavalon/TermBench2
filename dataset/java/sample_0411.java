public class sample_0411 {
    public static int[] transform_coordinates(int x, int y, int z, int[][] matrix) {
        int[] result = new int[3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j == 0) {
                    result[i] += x * matrix[i][j];
                } else if (j == 1) {
                    result[i] += y * matrix[i][j];
                } else {
                    result[i] += z * matrix[i][j];
                }
            }
        }
        return result;
    }

    public static int[] apply_transformation(int iterations) {
        int[][] matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        int x = 1, y = 1, z = 1;
        for (int _ = 0; _ < iterations; _++) {
            int[] result = transform_coordinates(x, y, z, matrix);
            x = result[0];
            y = result[1];
            z = result[2];
            matrix = new int[][]{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        }
        return new int[]{x, y, z};
    }

    public static void main(String[] args) {
        while (true) {
            int[] result = apply_transformation(100);
            System.out.println("(" + result[0] + ", " + result[1] + ", " + result[2] + ")");
        }
    }
}