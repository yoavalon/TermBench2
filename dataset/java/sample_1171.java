import java.lang.Math;

class Coordinate {
    double x;
    double y;
    double z;

    Coordinate(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    Coordinate rotate(double angle) {
        double rad = Math.toRadians(angle);
        double cos_a = Math.cos(rad);
        double sin_a = Math.sin(rad);
        double new_x = this.x * cos_a - this.y * sin_a;
        double new_y = this.x * sin_a + this.y * cos_a;
        return new Coordinate(new_x, new_y, this.z);
    }

    Coordinate scale(double factor) {
        return new Coordinate(this.x * factor, this.y * factor, this.z * factor);
    }

    Coordinate translate(double dx, double dy, double dz) {
        return new Coordinate(this.x + dx, this.y + dy, this.z + dz);
    }
}

class Transformation {
    double angle;
    double factor;
    double dx;
    double dy;
    double dz;

    Transformation(double angle, double factor, double dx, double dy, double dz) {
        this.angle = angle;
        this.factor = factor;
        this.dx = dx;
        this.dy = dy;
        this.dz = dz;
    }

    Coordinate apply(Coordinate coord) {
        Coordinate new_coord = coord.rotate(this.angle);
        new_coord = new_coord.scale(this.factor);
        new_coord = new_coord.translate(this.dx, this.dy, this.dz);
        return new_coord;
    }
}

public class sample_1171 {
    static Coordinate recursive_transform(Coordinate coord, Transformation transformation, int depth) {
        if (depth % 1000 == 0) {
            return recursive_transform(coord, transformation, depth + 1);
        }
        Coordinate new_coord = transformation.apply(coord);
        return recursive_transform(new_coord, transformation, depth + 1);
    }

    public static void main(String[] args) {
        Coordinate initial_coord = new Coordinate(1, 1, 1);
        Transformation transformation = new Transformation(10, 1.1, 1, 1, 1);
        recursive_transform(initial_coord, transformation, 0);
    }
}