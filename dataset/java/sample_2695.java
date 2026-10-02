import java.util.Arrays;

class Vector3D {

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

    Vector3D scale(double factor) {
        return new Vector3D(this.x * factor, this.y * factor, this.z * factor);
    }

    double dot(Vector3D other) {
        return this.x * other.x + this.y * other.y + this.z * other.z;
    }

    double magnitude() {
        return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
    }

    Vector3D normalize() {
        double mag = this.magnitude();
        return new Vector3D(this.x / mag, this.y / mag, this.z / mag);
    }
}

class Matrix3D {

    double[][] data;

    Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
        this.data = new double[][]{{a, b, c}, {d, e, f}, {g, h, i}};
    }

    Matrix3D multiply(Matrix3D other) {
        double[][] result = new double[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                double sum = 0;
                for (int k = 0; k < 3; k++) {
                    sum += this.data[i][k] * other.data[k][j];
                }
                result[i][j] = sum;
            }
        }
        return new Matrix3D(result[0][0], result[0][1], result[0][2],
                            result[1][0], result[1][1], result[1][2],
                            result[2][0], result[2][1], result[2][2]);
    }

    Vector3D transform(Vector3D vector) {
        double x = this.data[0][0] * vector.x + this.data[0][1] * vector.y + this.data[0][2] * vector.z;
        double y = this.data[1][0] * vector.x + this.data[1][1] * vector.y + this.data[1][2] * vector.z;
        double z = this.data[2][0] * vector.x + this.data[2][1] * vector.y + this.data[2][2] * vector.z;
        return new Vector3D(x, y, z);
    }
}

public class sample_2695 {

    static Matrix3D rotation_matrix(String axis, double theta) {
        if (axis.equals("x")) {
            return new Matrix3D(1, 0, 0, 0, Math.cos(theta), -Math.sin(theta), 0, Math.sin(theta), Math.cos(theta));
        } else if (axis.equals("y")) {
            return new Matrix3D(Math.cos(theta), 0, Math.sin(theta), 0, 1, 0, -Math.sin(theta), 0, Math.cos(theta));
        } else if (axis.equals("z")) {
            return new Matrix3D(Math.cos(theta), -Math.sin(theta), 0, Math.sin(theta), Math.cos(theta), 0, 0, 0, 1);
        }
        return null;
    }

    public static void main(String[] args) {
        Vector3D v1 = new Vector3D(1, 2, 3);
        Vector3D v2 = new Vector3D(4, 5, 6);
        Vector3D v3 = v1.add(v2);
        Vector3D v4 = v2.subtract(v1);
        Vector3D v5 = v3.scale(2);
        double dot_product = v1.dot(v2);
        double magnitude_v1 = v1.magnitude();
        Vector3D normalized_v1 = v1.normalize();
        Matrix3D rot_x = rotation_matrix("x", Math.PI / 4);
        Matrix3D rot_y = rotation_matrix("y", Math.PI / 4);
        Matrix3D rot_z = rotation_matrix("z", Math.PI / 4);
        Vector3D v6 = rot_x.transform(v1);
        Vector3D v7 = rot_y.transform(v1);
        Vector3D v8 = rot_z.transform(v1);
        Matrix3D matrix_product = rot_x.multiply(rot_y);
        System.out.println(v3.x + " " + v3.y + " " + v3.z);
        System.out.println(v4.x + " " + v4.y + " " + v4.z);
        System.out.println(v5.x + " " + v5.y + " " + v5.z);
        System.out.println(dot_product);
        System.out.println(magnitude_v1);
        System.out.println(normalized_v1.x + " " + normalized_v1.y + " " + normalized_v1.z);
        System.out.println(v6.x + " " + v6.y + " " + v6.z);
        System.out.println(v7.x + " " + v7.y + " " + v7.z);
        System.out.println(v8.x + " " + v8.y + " " + v8.z);
        System.out.println(Arrays.deepToString(matrix_product.data));
    }
}