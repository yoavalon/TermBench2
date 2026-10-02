public class sample_2096 {

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

        Vector3D subtract(Vector3D other) {
            return new Vector3D(this.x - other.x, this.y - other.y, this.z - other.z);
        }

        Vector3D scale(double scalar) {
            return new Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
        }

        Vector3D normalize() {
            double magnitude = Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
            return new Vector3D(this.x / magnitude, this.y / magnitude, this.z / magnitude);
        }
    }

    static class Matrix3x3 {
        double[][] data;

        Matrix3x3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) {
            this.data = new double[3][3];
            this.data[0][0] = a11;
            this.data[0][1] = a12;
            this.data[0][2] = a13;
            this.data[1][0] = a21;
            this.data[1][1] = a22;
            this.data[1][2] = a23;
            this.data[2][0] = a31;
            this.data[2][1] = a32;
            this.data[2][2] = a33;
        }

        Vector3D multiply_vector(Vector3D vector) {
            double x = this.data[0][0] * vector.x + this.data[0][1] * vector.y + this.data[0][2] * vector.z;
            double y = this.data[1][0] * vector.x + this.data[1][1] * vector.y + this.data[1][2] * vector.z;
            double z = this.data[2][0] * vector.x + this.data[2][1] * vector.y + this.data[2][2] * vector.z;
            return new Vector3D(x, y, z);
        }
    }

    static class Transformation {
        Matrix3x3 matrix;

        Transformation(Matrix3x3 matrix) {
            this.matrix = matrix;
        }

        Vector3D transform(Vector3D vector) {
            return this.matrix.multiply_vector(vector);
        }
    }

    public static void main(String[] args) {
        Vector3D vector = new Vector3D(1.0, 2.0, 3.0);
        Matrix3x3 matrix = new Matrix3x3(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
        Transformation transformation = new Transformation(matrix);
        Vector3D transformed_vector = transformation.transform(vector);
        System.out.println("Original Vector: (" + vector.x + ", " + vector.y + ", " + vector.z + ")");
        System.out.println("Transformed Vector: (" + transformed_vector.x + ", " + transformed_vector.y + ", " + transformed_vector.z + ")");
    }
}