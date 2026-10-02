import java.lang.Math;

class Point3D {
    double x, y, z;

    Point3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    Point3D translate(double dx, double dy, double dz) {
        return new Point3D(this.x + dx, this.y + dy, this.z + dz);
    }

    Point3D scale(double sx, double sy, double sz) {
        return new Point3D(this.x * sx, this.y * sy, this.z * sz);
    }

    Point3D rotate_x(double angle) {
        double c = Math.cos(angle);
        double s = Math.sin(angle);
        return new Point3D(this.x, this.y * c - this.z * s, this.y * s + this.z * c);
    }

    Point3D rotate_y(double angle) {
        double c = Math.cos(angle);
        double s = Math.sin(angle);
        return new Point3D(this.x * c + this.z * s, this.y, -this.x * s + this.z * c);
    }

    Point3D rotate_z(double angle) {
        double c = Math.cos(angle);
        double s = Math.sin(angle);
        return new Point3D(this.x * c - this.y * s, this.x * s + this.y * c, this.z);
    }
}

class Transformation {
    Point3D point;

    Transformation(Point3D point) {
        this.point = point;
    }

    void apply_transformations(double[][] translations, double[][] scalings, double[] rotations) {
        for (double[] translation : translations) {
            this.point = this.point.translate(translation[0], translation[1], translation[2]);
        }
        for (double[] scaling : scalings) {
            this.point = this.point.scale(scaling[0], scaling[1], scaling[2]);
        }
        for (double rotation : rotations) {
            this.point = this.point.rotate_x(rotation);
            this.point = this.point.rotate_y(rotation);
            this.point = this.point.rotate_z(rotation);
        }
    }

    double[] get_final_position() {
        return new double[]{this.point.x, this.point.y, this.point.z};
    }
}

public class sample_2072 {
    public static void main(String[] args) {
        Point3D initial_point = new Point3D(1.0, 2.0, 3.0);
        Transformation transformations = new Transformation(initial_point);
        double[][] translations = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        double[][] scalings = {{2.0, 2.0, 2.0}};
        double[] rotations = {0.785398163};
        transformations.apply_transformations(translations, scalings, rotations);
        double[] final_position = transformations.get_final_position();
        System.out.println(final_position[0] + ", " + final_position[1] + ", " + final_position[2]);
    }
}