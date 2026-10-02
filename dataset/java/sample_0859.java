public class sample_0859 {

    static class Vector {
        double x, y, z;

        Vector(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        Vector add(Vector other) {
            return new Vector(this.x + other.x, this.y + other.y, this.z + other.z);
        }

        Vector scale(double factor) {
            return new Vector(this.x * factor, this.y * factor, this.z * factor);
        }

        @Override
        public String toString() {
            return "Vector(" + x + ", " + y + ", " + z + ")";
        }
    }

    static class Matrix {
        double a11, a12, a13, a21, a22, a23, a31, a32, a33;

        Matrix(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) {
            this.a11 = a11;
            this.a12 = a12;
            this.a13 = a13;
            this.a21 = a21;
            this.a22 = a22;
            this.a23 = a23;
            this.a31 = a31;
            this.a32 = a32;
            this.a33 = a33;
        }

        Vector multiply(Vector vector) {
            double x = this.a11 * vector.x + this.a12 * vector.y + this.a13 * vector.z;
            double y = this.a21 * vector.x + this.a22 * vector.y + this.a23 * vector.z;
            double z = this.a31 * vector.x + this.a32 * vector.y + this.a33 * vector.z;
            return new Vector(x, y, z);
        }

        @Override
        public String toString() {
            return "Matrix(" + a11 + ", " + a12 + ", " + a13 + ", " + a21 + ", " + a22 + ", " + a23 + ", " + a31 + ", " + a32 + ", " + a33 + ")";
        }
    }

    static Vector transform_vector(Matrix matrix, Vector vector, int depth) {
        if (depth == 0) {
            return vector;
        }
        Vector transformed = matrix.multiply(vector);
        return transform_vector(matrix, transformed, depth - 1);
    }

    public static void main(String[] args) {
        Vector vector = new Vector(1, 2, 3);
        Matrix matrix = new Matrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
        int depth = 5;
        Vector result = transform_vector(matrix, vector, depth);
        System.out.println(result);
    }
}