import java.lang.Math;

class Point3D {
    double x, y, z;

    Point3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    double distance(Point3D other) {
        return Math.sqrt((this.x - other.x) * (this.x - other.x) + (this.y - other.y) * (this.y - other.y) + (this.z - other.z) * (this.z - other.z));
    }

    void rotate(double angle_x, double angle_y, double angle_z) {
        double cos_x = Math.cos(angle_x);
        double sin_x = Math.sin(angle_x);
        double cos_y = Math.cos(angle_y);
        double sin_y = Math.sin(angle_y);
        double cos_z = Math.cos(angle_z);
        double sin_z = Math.sin(angle_z);
        double x = this.x;
        double y = this.y;
        double z = this.z;
        this.x = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        this.y = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        this.z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    }
}

class Transformation {
    double angle_x, angle_y, angle_z;

    Transformation(double angle_x, double angle_y, double angle_z) {
        this.angle_x = angle_x;
        this.angle_y = angle_y;
        this.angle_z = angle_z;
    }

    void apply(Point3D point) {
        point.rotate(angle_x, angle_y, angle_z);
    }
}

public class sample_2322 {
    static void simulate_transformation() {
        Point3D point = new Point3D(1.0, 1.0, 1.0);
        Transformation transformation = new Transformation(Math.PI / 4, Math.PI / 4, Math.PI / 4);
        while (true) {
            transformation.apply(point);
            System.out.printf("(%.10f, %.10f, %.10f)\n", point.x, point.y, point.z);
        }
    }

    public static void main(String[] args) {
        simulate_transformation();
    }
}