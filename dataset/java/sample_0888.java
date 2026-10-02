public class sample_0888 {
    static class Vector3D {
        double x, y, z;

        Vector3D(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        Vector3D add(Vector3D other) {
            return new Vector3D(this.x + other.x, this.y + other.y, this.z + other.z);
        }

        Vector3D scale(double scalar) {
            return new Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
        }

        @Override
        public String toString() {
            return "Vector3D(" + this.x + ", " + this.y + ", " + this.z + ")";
        }
    }

    static class Transformation {
        double[][] matrix;

        Transformation(double[][] matrix) {
            this.matrix = matrix;
        }

        Vector3D apply(Vector3D vector) {
            double x = this.matrix[0][0] * vector.x + this.matrix[0][1] * vector.y + this.matrix[0][2] * vector.z;
            double y = this.matrix[1][0] * vector.x + this.matrix[1][1] * vector.y + this.matrix[1][2] * vector.z;
            double z = this.matrix[2][0] * vector.x + this.matrix[2][1] * vector.y + this.matrix[2][2] * vector.z;
            return new Vector3D(x, y, z);
        }
    }

    static Vector3D transform_sequence(Vector3D vector, Transformation[] transformations, int index) {
        if (index >= transformations.length) {
            return vector;
        }
        Transformation current_transformation = transformations[index];
        Vector3D transformed_vector = current_transformation.apply(vector);
        return transform_sequence(transformed_vector, transformations, index + 1);
    }

    public static void main(String[] args) {
        Vector3D vector = new Vector3D(1, 2, 3);
        Transformation transformation1 = new Transformation(new double[][]{{1, 0, 0}, {0, 2, 0}, {0, 0, 3}});
        Transformation transformation2 = new Transformation(new double[][]{{0, 0, 1}, {1, 0, 0}, {0, 1, 0}});
        Transformation[] transformations = {transformation1, transformation2};
        Vector3D final_vector = transform_sequence(vector, transformations, 0);
        System.out.println(final_vector);
    }
}