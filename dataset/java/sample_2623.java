import java.util.Arrays;

public class sample_2623 {

    static class Matrix {
        double[][] data;
        int rows;
        int cols;

        Matrix(double[][] data) {
            this.data = data;
            this.rows = data.length;
            this.cols = rows > 0 ? data[0].length : 0;
        }

        Matrix multiply(Matrix other) {
            double[][] result = new double[this.rows][other.cols];
            for (int i = 0; i < this.rows; i++) {
                for (int j = 0; j < other.cols; j++) {
                    for (int k = 0; k < other.rows; k++) {
                        result[i][j] += this.data[i][k] * other.data[k][j];
                    }
                }
            }
            return new Matrix(result);
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (double[] row : data) {
                sb.append(Arrays.toString(row)).append("\n");
            }
            return sb.toString();
        }
    }

    static Matrix rotation_matrix(char axis, double theta) {
        if (axis == 'x') {
            return new Matrix(new double[][]{
                    {1, 0, 0},
                    {0, Math.cos(theta), -Math.sin(theta)},
                    {0, Math.sin(theta), Math.cos(theta)}
            });
        } else if (axis == 'y') {
            return new Matrix(new double[][]{
                    {Math.cos(theta), 0, Math.sin(theta)},
                    {0, 1, 0},
                    {-Math.sin(theta), 0, Math.cos(theta)}
            });
        } else if (axis == 'z') {
            return new Matrix(new double[][]{
                    {Math.cos(theta), -Math.sin(theta), 0},
                    {Math.sin(theta), Math.cos(theta), 0},
                    {0, 0, 1}
            });
        }
        return null;
    }

    static double[] transform_point(Matrix matrix, double[] point) {
        Matrix point_matrix = new Matrix(new double[][]{
                {point[0]},
                {point[1]},
                {point[2]}
        });
        Matrix transformed = matrix.multiply(point_matrix);
        return new double[]{transformed.data[0][0], transformed.data[1][0], transformed.data[2][0]};
    }

    public static void main(String[] args) {
        double[] point = {1, 2, 3};
        double theta = 0.785398;
        Matrix matrix_x = rotation_matrix('x', theta);
        Matrix matrix_y = rotation_matrix('y', theta);
        Matrix matrix_z = rotation_matrix('z', theta);
        double[] transformed_x = transform_point(matrix_x, point);
        double[] transformed_y = transform_point(matrix_y, point);
        double[] transformed_z = transform_point(matrix_z, point);
        System.out.println("Transformed by X-axis: " + Arrays.toString(transformed_x));
        System.out.println("Transformed by Y-axis: " + Arrays.toString(transformed_y));
        System.out.println("Transformed by Z-axis: " + Arrays.toString(transformed_z));
    }
}