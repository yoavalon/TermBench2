public class sample_1156 {

    static class Coordinate {
        double x, y, z;

        Coordinate(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        Coordinate rotate_x(double angle) {
            double rad = Math.toRadians(angle);
            double cos_val = Math.cos(rad);
            double sin_val = Math.sin(rad);
            return new Coordinate(this.x, this.y * cos_val - this.z * sin_val, this.y * sin_val + this.z * cos_val);
        }

        Coordinate rotate_y(double angle) {
            double rad = Math.toRadians(angle);
            double cos_val = Math.cos(rad);
            double sin_val = Math.sin(rad);
            return new Coordinate(this.x * cos_val + this.z * sin_val, this.y, -this.x * sin_val + this.z * cos_val);
        }

        Coordinate rotate_z(double angle) {
            double rad = Math.toRadians(angle);
            double cos_val = Math.cos(rad);
            double sin_val = Math.sin(rad);
            return new Coordinate(this.x * cos_val - this.y * sin_val, this.x * sin_val + this.y * cos_val, this.z);
        }
    }

    static Coordinate transform(Coordinate coord, double angle, char axis) {
        if (axis == 'x') {
            return coord.rotate_x(angle);
        } else if (axis == 'y') {
            return coord.rotate_y(angle);
        } else if (axis == 'z') {
            return coord.rotate_z(angle);
        }
        return coord;
    }

    static Coordinate recursive_transform(Coordinate coord, double angle, char axis) {
        Coordinate new_coord = transform(coord, angle, axis);
        return recursive_transform(new_coord, angle, axis);
    }

    public static void main(String[] args) {
        Coordinate initial_coord = new Coordinate(1, 0, 0);
        Coordinate final_coord = recursive_transform(initial_coord, 90, 'z');
        System.out.println(final_coord.x + " " + final_coord.y + " " + final_coord.z);
    }
}