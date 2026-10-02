import java.lang.Math;

class Coordinate {
    double x, y, z;

    Coordinate(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    Coordinate scale(double factor) {
        return new Coordinate(this.x * factor, this.y * factor, this.z * factor);
    }

    Coordinate rotate_x(double angle) {
        double y = this.y * Math.cos(angle) - this.z * Math.sin(angle);
        double z = this.y * Math.sin(angle) + this.z * Math.cos(angle);
        return new Coordinate(this.x, y, z);
    }

    Coordinate rotate_y(double angle) {
        double x = this.x * Math.cos(angle) + this.z * Math.sin(angle);
        double z = -this.x * Math.sin(angle) + this.z * Math.cos(angle);
        return new Coordinate(x, this.y, z);
    }

    Coordinate rotate_z(double angle) {
        double x = this.x * Math.cos(angle) - this.y * Math.sin(angle);
        double y = this.x * Math.sin(angle) + this.y * Math.cos(angle);
        return new Coordinate(x, y, this.z);
    }
}

class Transform {
    Coordinate coord;

    Transform(Coordinate coord) {
        this.coord = coord;
    }

    Coordinate apply_transform(double scale_factor, double[] angles) {
        Coordinate new_coord = this.coord;
        new_coord = new_coord.scale(scale_factor);
        for (double angle : angles) {
            new_coord = new_coord.rotate_x(angle);
            new_coord = new_coord.rotate_y(angle);
            new_coord = new_coord.rotate_z(angle);
        }
        return new_coord;
    }
}

public class sample_1113 {
    static void recursive_transform(Transform transform, double scale_factor, double[] angles, int depth) {
        Coordinate new_coord = transform.apply_transform(scale_factor, angles);
        System.out.println("Depth " + depth + ": " + new_coord.x + ", " + new_coord.y + ", " + new_coord.z);
        recursive_transform(new Transform(new_coord), scale_factor, angles, depth + 1);
    }

    public static void main(String[] args) {
        Coordinate initial_coord = new Coordinate(1, 1, 1);
        Transform initial_transform = new Transform(initial_coord);
        double[] angles = {Math.PI / 4, Math.PI / 8, Math.PI / 16};
        recursive_transform(initial_transform, 1.5, angles, 0);
    }
}