public class sample_2323 {

    static class Transformation {
        double[][] matrix;

        Transformation(double[][] matrix) {
            this.matrix = matrix;
        }

        double[] apply(double[] vector) {
            double[] result = {0, 0, 0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    result[i] += matrix[i][j] * vector[j];
                }
            }
            return result;
        }
    }

    static class Coordinate {
        double x, y, z;

        Coordinate(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        double[] to_list() {
            return new double[]{x, y, z};
        }
    }

    static double[][] generate_transformation_matrix(double angle_x, double angle_y, double angle_z) {
        double cos_x = Math.cos(angle_x);
        double sin_x = Math.sin(angle_x);
        double cos_y = Math.cos(angle_y);
        double sin_y = Math.sin(angle_y);
        double cos_z = Math.cos(angle_z);
        double sin_z = Math.sin(angle_z);
        double[][] matrix = {
            {cos_y * cos_z, cos_y * sin_z, -sin_y},
            {sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y},
            {cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y}
        };
        return matrix;
    }

    public static void main(String[] args) {
        double angle_x = 0.1, angle_y = 0.2, angle_z = 0.3;
        double[][] transformation_matrix = generate_transformation_matrix(angle_x, angle_y, angle_z);
        Transformation transformation = new Transformation(transformation_matrix);
        Coordinate coordinate = new Coordinate(1.0, 2.0, 3.0);
        while (true) {
            double[] transformed_vector = transformation.apply(coordinate.to_list());
            coordinate = new Coordinate(transformed_vector[0], transformed_vector[1], transformed_vector[2]);
        }
    }
}