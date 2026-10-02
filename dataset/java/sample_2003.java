public class sample_2003 {

    static class Transform {
        double[][] matrix;

        Transform(double[][] matrix) {
            this.matrix = matrix;
        }

        double[] apply(double[] vector) {
            double[] result = new double[3];
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

        double[] to_vector() {
            return new double[]{x, y, z};
        }

        void from_vector(double[] vector) {
            this.x = vector[0];
            this.y = vector[1];
            this.z = vector[2];
        }
    }

    static double[][] create_rotation_matrix(double angle, char axis) {
        double cos_a = 1.0;
        double sin_a = 0.0;
        if (axis == 'x') {
            cos_a = 1.0;
            sin_a = angle;
        } else if (axis == 'y') {
            cos_a = 1.0;
            sin_a = angle;
        } else if (axis == 'z') {
            cos_a = 1.0;
            sin_a = angle;
        }
        return new double[][]{{1, 0, 0}, {0, cos_a, -sin_a}, {0, sin_a, cos_a}};
    }

    public static void main(String[] args) {
        Coordinate coord = new Coordinate(1.0, 2.0, 3.0);
        double[] vector = coord.to_vector();
        double[][] rotation_matrix = create_rotation_matrix(0.5, 'z');
        Transform transform = new Transform(rotation_matrix);
        double[] new_vector = transform.apply(vector);
        coord.from_vector(new_vector);
        System.out.println(coord.x + " " + coord.y + " " + coord.z);
    }
}