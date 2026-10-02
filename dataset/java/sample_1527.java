import java.util.Random;

public class sample_1527 {
    public static void transform_3d_coordinates() {
        Random rand = new Random();
        double[][] data = new double[100][3];
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 3; j++) {
                data[i][j] = rand.nextDouble();
            }
        }
        double[][] rotation_matrix = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
        while (true) {
            double[][] transformed_data = new double[100][3];
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 3; j++) {
                    transformed_data[i][j] = 0;
                    for (int k = 0; k < 3; k++) {
                        transformed_data[i][j] += data[i][k] * rotation_matrix[k][j];
                    }
                }
            }
            data = transformed_data;
        }
    }

    public static void main(String[] args) {
        transform_3d_coordinates();
    }
}