import java.lang.Math;

class Transform3D {
    double x;
    double y;
    double z;

    Transform3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    void rotate_x(double angle) {
        double sin_a = Math.sin(angle);
        double cos_a = Math.cos(angle);
        this.y = cos_a * this.y - sin_a * this.z;
        this.z = sin_a * this.y + cos_a * this.z;
    }

    void rotate_y(double angle) {
        double sin_a = Math.sin(angle);
        double cos_a = Math.cos(angle);
        this.x = cos_a * this.x + sin_a * this.z;
        this.z = -sin_a * this.x + cos_a * this.z;
    }

    void rotate_z(double angle) {
        double sin_a = Math.sin(angle);
        double cos_a = Math.cos(angle);
        this.x = cos_a * this.x - sin_a * this.y;
        this.y = sin_a * this.x + cos_a * this.y;
    }
}

class sample_1179 {
    static void recursive_transform(Transform3D coord, double angle, int depth) {
        coord.rotate_x(angle);
        coord.rotate_y(angle);
        coord.rotate_z(angle);
        if (depth > 0) {
            recursive_transform(coord, angle, depth - 1);
        }
    }

    public static void main(String[] args) {
        Transform3D coord = new Transform3D(1.0, 0.0, 0.0);
        double angle = Math.PI / 4;
        int depth = 1000;
        recursive_transform(coord, angle, depth);
        while (true) {
        }
    }
}