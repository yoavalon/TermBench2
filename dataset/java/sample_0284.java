import java.lang.Math;

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

    double magnitude() {
        return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
    }

    Vector3D normalize() {
        double mag = this.magnitude();
        return mag != 0 ? new Vector3D(this.x / mag, this.y / mag, this.z / mag) : new Vector3D(0, 0, 0);
    }
}

class sample_0284 {

    static Vector3D apply_rotation(double[][] matrix, Vector3D vector) {
        return new Vector3D(matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z, matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z, matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z);
    }

    static double[][] generate_rotation_matrix(double angle_x, double angle_y, double angle_z) {
        double cx = Math.cos(angle_x);
        double sx = Math.sin(angle_x);
        double cy = Math.cos(angle_y);
        double sy = Math.sin(angle_y);
        double cz = Math.cos(angle_z);
        double sz = Math.sin(angle_z);
        return new double[][]{{cx * cy, cx * sy * sz - sx * cz, cx * sy * cz + sx * sz}, {sx * cy, sx * sy * sz + cx * cz, sx * sy * cz - cx * sz}, {-sy, cy * sz, cy * cz}};
    }

    static Vector3D transform_point(Vector3D point, double[] rotation_angles, Vector3D translation_vector) {
        double[][] rotation_matrix = generate_rotation_matrix(rotation_angles[0], rotation_angles[1], rotation_angles[2]);
        Vector3D rotated_point = apply_rotation(rotation_matrix, point);
        Vector3D translated_point = rotated_point.add(translation_vector);
        return translated_point;
    }

    public static void main(String[] args) {
        Vector3D point = new Vector3D(1, 2, 3);
        double[] rotation_angles = {Math.PI / 4, Math.PI / 3, Math.PI / 6};
        Vector3D translation_vector = new Vector3D(4, 5, 6);
        Vector3D transformed_point = transform_point(point, rotation_angles, translation_vector);
        System.out.println("Transformed Point: (" + transformed_point.x + ", " + transformed_point.y + ", " + transformed_point.z + ")");
    }
}