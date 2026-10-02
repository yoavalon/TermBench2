public class sample_0154 {
    public static void main(String[] args) {
        int[][] coords = {{1, 2, 3}, {4, 5, 6}};
        int[][][] matrices = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {{0, 0, 1}, {1, 0, 0}, {0, 1, 0}}};
        int[][] result = apply_transformations(coords, matrices);
        for (int[] coord : result) {
            System.out.print("(" + coord[0] + ", " + coord[1] + ", " + coord[2] + ") ");
        }
    }

    public static int[] transform_coordinates(int x, int y, int z, int[][] matrix) {
        int x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
        int y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
        int z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
        return new int[]{x_new, y_new, z_new};
    }

    public static int[][] apply_transformations(int[][] coord_list, int[][][] matrix_list) {
        int[][] transformed_coords = new int[coord_list.length][3];
        for (int i = 0; i < coord_list.length; i++) {
            int[] coord = coord_list[i];
            for (int j = 0; j < matrix_list.length; j++) {
                int[][] matrix = matrix_list[j];
                coord = transform_coordinates(coord[0], coord[1], coord[2], matrix);
            }
            transformed_coords[i] = coord;
        }
        return transformed_coords;
    }
}