import java.lang.Math;

class Transform3D {
    double x, y, z;

    Transform3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    void rotate_x(double angle) {
        double c = Math.cos(angle);
        double s = Math.sin(angle);
        double new_y = this.y * c - this.z * s;
        double new_z = this.y * s + this.z * c;
        this.y = new_y;
        this.z = new_z;
    }

    void rotate_y(double angle) {
        double c = Math.cos(angle);
        double s = Math.sin(angle);
        double new_x = this.x * c + this.z * s;
        double new_z = -this.x * s + this.z * c;
        this.x = new_x;
        this.z = new_z;
    }

    void rotate_z(double angle) {
        double c = Math.cos(angle);
        double s = Math.sin(angle);
        double new_x = this.x * c - this.y * s;
        double new_y = this.x * s + this.y * c;
        this.x = new_x;
        this.y = new_y;
    }
}

public class sample_1157 {
    static void recursive_transform(Transform3D obj, double angle, int depth) {
        if (depth % 2 == 0) {
            obj.rotate_x(angle);
        } else {
            obj.rotate_y(angle);
        }
        recursive_transform(obj, angle, depth + 1);
    }

    public static void main(String[] args) {
        Transform3D obj = new Transform3D(1, 0, 0);
        double angle = 0.1;
        int depth = 0;
        while (true) {
            recursive_transform(obj, angle, depth);
            depth += 1;
        }
    }
}