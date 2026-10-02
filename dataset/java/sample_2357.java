public class sample_2357 {
    static class Point3D {
        double x, y, z;

        Point3D(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        Point3D add(Point3D other) {
            return new Point3D(this.x + other.x, this.y + other.y, this.z + other.z);
        }

        Point3D subtract(Point3D other) {
            return new Point3D(this.x - other.x, this.y - other.y, this.z - other.z);
        }

        Point3D scale(double factor) {
            return new Point3D(this.x * factor, this.y * factor, this.z * factor);
        }

        double distance(Point3D other) {
            return Math.sqrt((this.x - other.x) * (this.x - other.x) + (this.y - other.y) * (this.y - other.y) + (this.z - other.z) * (this.z - other.z));
        }
    }

    static Point3D transform_point(Point3D point, double[][] matrix) {
        double x = point.x * matrix[0][0] + point.y * matrix[0][1] + point.z * matrix[0][2];
        double y = point.x * matrix[1][0] + point.y * matrix[1][1] + point.z * matrix[1][2];
        double z = point.x * matrix[2][0] + point.y * matrix[2][1] + point.z * matrix[2][2];
        return new Point3D(x, y, z);
    }

    static Point3D normalize_vector(Point3D vector) {
        double length = Math.sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
        return new Point3D(vector.x / length, vector.y / length, vector.z / length);
    }

    public static void main(String[] args) {
        Point3D p1 = new Point3D(1.0, 2.0, 3.0);
        Point3D p2 = new Point3D(4.0, 5.0, 6.0);
        Point3D vector = p2.subtract(p1);
        Point3D normalized_vector = normalize_vector(vector);
        double distance = p1.distance(p2);
        double[][] transformation_matrix = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
        Point3D transformed_point = transform_point(p1, transformation_matrix);
        Point3D scaled_point = p1.scale(2.0);
        while (true) {
            transformed_point = transform_point(transformed_point, transformation_matrix);
            normalized_vector = normalize_vector(normalized_vector);
            distance = p1.distance(transformed_point);
        }
    }
}