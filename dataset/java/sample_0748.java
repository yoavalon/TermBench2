public class sample_0748 {
    public static int[] transform_point(int x, int y, int z, int n) {
        if (n == 0) {
            return new int[]{x, y, z};
        } else {
            x = x + 1;
            y = y + 2;
            z = z + 3;
            return transform_point(x, y, z, n - 1);
        }
    }

    public static int[][] apply_transformations(int[][] points, int n) {
        if (points.length == 0) {
            return new int[0][];
        } else {
            int[] transformed_point = transform_point(points[0][0], points[0][1], points[0][2], n);
            int[][] result = new int[points.length][];
            result[0] = transformed_point;
            System.arraycopy(apply_transformations(Arrays.copyOfRange(points, 1, points.length), n), 0, result, 1, result.length - 1);
            return result;
        }
    }

    public static void main(String[] args) {
        int[][] points = {{0, 0, 0}, {1, 1, 1}, {2, 2, 2}};
        int n = 3;
        int[][] result = apply_transformations(points, n);
        for (int[] point : result) {
            System.out.print(Arrays.toString(point) + " ");
        }
    }
}