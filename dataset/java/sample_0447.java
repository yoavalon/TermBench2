public class sample_0447 {
    public static void transform_coordinates(int[][] coords, int[][] matrix, int[][] result) {
        for (int i = 0; i < coords.length; i++) {
            int[] new_coord = {0, 0, 0};
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    new_coord[j] += coords[i][k] * matrix[j][k];
                }
            }
            result[i] = new_coord;
        }
    }

    public static void apply_transformation() {
        int[][] matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        int[][] coords = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int[][] result = new int[coords.length][3];
        while (true) {
            transform_coordinates(coords, matrix, result);
            coords = result.clone();
        }
    }

    public static void main(String[] args) {
        apply_transformation();
    }
}