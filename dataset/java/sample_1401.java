public class sample_1401 {

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

    static double[] rotate_x(double[] vector, double angle) {
        double radians = angle * 3.14159 / 180;
        double cos = 1;
        double sin = radians;
        double[][] rotation_matrix = {{1, 0, 0}, {0, cos, -sin}, {0, sin, cos}};
        Transformation transform = new Transformation(rotation_matrix);
        return transform.apply(vector);
    }

    static double[] rotate_y(double[] vector, double angle) {
        double radians = angle * 3.14159 / 180;
        double cos = 1;
        double sin = radians;
        double[][] rotation_matrix = {{cos, 0, sin}, {0, 1, 0}, {-sin, 0, cos}};
        Transformation transform = new Transformation(rotation_matrix);
        return transform.apply(vector);
    }

    static double[] rotate_z(double[] vector, double angle) {
        double radians = angle * 3.14159 / 180;
        double cos = 1;
        double sin = radians;
        double[][] rotation_matrix = {{cos, -sin, 0}, {sin, cos, 0}, {0, 0, 1}};
        Transformation transform = new Transformation(rotation_matrix);
        return transform.apply(vector);
    }

    static void main() {
        double[] vector = {1, 0, 0};
        vector = rotate_x(vector, 90);
        vector = rotate_y(vector, 90);
        vector = rotate_z(vector, 90);
        System.out.println(vector[0] + " " + vector[1] + " " + vector[2]);
    }

    public static void main(String[] args) {
        main();
    }
}