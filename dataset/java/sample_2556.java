public class sample_2556 {
    public static void main(String[] args) {
        int[][] points = {{1, 2, 3}, {4, 5, 6}};
        int[][] sequence = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        int[][] transformed_points = apply_sequence(points, sequence);
        for (int[] point : transformed_points) {
            System.out.print("(");
            for (int i = 0; i < point.length; i++) {
                System.out.print(point[i]);
                if (i < point.length - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println(")");
        }
    }

    public static int[] transform_point(int x, int y, int z, int a, int b, int c) {
        return new int[]{x + a, y + b, z + c};
    }

    public static int[][] apply_sequence(int[][] points, int[][] seq) {
        int[][] result = new int[points.length][];
        for (int i = 0; i < points.length; i++) {
            int[] point = points[i];
            for (int[] transform : seq) {
                point = transform_point(point[0], point[1], point[2], transform[0], transform[1], transform[2]);
            }
            result[i] = point;
        }
        return result;
    }
}