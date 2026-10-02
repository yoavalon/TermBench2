import java.util.Random;

class TransformationMatrix {
    double[][] matrix;

    TransformationMatrix(double[][] matrix) {
        this.matrix = matrix;
    }

    TransformationMatrix multiply(TransformationMatrix other) {
        double[][] result = new double[matrix.length][other.matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < other.matrix[0].length; j++) {
                double sum = 0;
                for (int k = 0; k < other.matrix.length; k++) {
                    sum += matrix[i][k] * other.matrix[k][j];
                }
                result[i][j] = sum;
            }
        }
        return new TransformationMatrix(result);
    }
}

class Vector {
    double x, y, z;

    Vector(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    Vector apply_transformation(TransformationMatrix matrix) {
        double[] transformed = new double[matrix.matrix.length];
        for (int i = 0; i < matrix.matrix.length; i++) {
            double sum = 0;
            for (int j = 0; j < matrix.matrix[0].length; j++) {
                sum += matrix.matrix[i][j] * (j == 0 ? x : (j == 1 ? y : z));
            }
            transformed[i] = sum;
        }
        return new Vector(transformed[0], transformed[1], transformed[2]);
    }
}

class sample_0504 {
    static TransformationMatrix generate_transformation_matrix(double rotation_angle) {
        double cos_val = Math.cos(rotation_angle);
        double sin_val = Math.sin(rotation_angle);
        return new TransformationMatrix(new double[][]{{cos_val, -sin_val, 0}, {sin_val, cos_val, 0}, {0, 0, 1}});
    }

    public static void main(String[] args) {
        Random random = new Random();
        Vector vector = new Vector(random.nextDouble(), random.nextDouble(), random.nextDouble());
        while (true) {
            double rotation_angle = random.nextDouble() * 3.14159;
            TransformationMatrix transformation_matrix = generate_transformation_matrix(rotation_angle);
            vector = vector.apply_transformation(transformation_matrix);
            System.out.println(vector.x + " " + vector.y + " " + vector.z);
        }
    }
}