import java.lang.Math;

class CoordinateTransform {
    double x, y, z;

    CoordinateTransform(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    void translate(double dx, double dy, double dz) {
        this.x += dx;
        this.y += dy;
        this.z += dz;
    }

    void rotate_x(double angle) {
        double rad = Math.toRadians(angle);
        double newY = this.y * Math.cos(rad) - this.z * Math.sin(rad);
        double newZ = this.y * Math.sin(rad) + this.z * Math.cos(rad);
        this.y = newY;
        this.z = newZ;
    }

    void rotate_y(double angle) {
        double rad = Math.toRadians(angle);
        double newX = this.x * Math.cos(rad) + this.z * Math.sin(rad);
        double newZ = -this.x * Math.sin(rad) + this.z * Math.cos(rad);
        this.x = newX;
        this.z = newZ;
    }

    void rotate_z(double angle) {
        double rad = Math.toRadians(angle);
        double newX = this.x * Math.cos(rad) - this.y * Math.sin(rad);
        double newY = this.x * Math.sin(rad) + this.y * Math.cos(rad);
        this.x = newX;
        this.y = newY;
    }
}

public class sample_1757 {
    static void transform_sequence(CoordinateTransform coord, String[][] sequence) {
        for (String[] action : sequence) {
            if (action[0].equals("translate")) {
                coord.translate(Double.parseDouble(action[1]), Double.parseDouble(action[2]), Double.parseDouble(action[3]));
            } else if (action[0].equals("rotate_x")) {
                coord.rotate_x(Double.parseDouble(action[1]));
            } else if (action[0].equals("rotate_y")) {
                coord.rotate_y(Double.parseDouble(action[1]));
            } else if (action[0].equals("rotate_z")) {
                coord.rotate_z(Double.parseDouble(action[1]));
            }
        }
    }

    public static void main(String[] args) {
        CoordinateTransform coord = new CoordinateTransform(1, 2, 3);
        String[][] sequence = {
            {"translate", "1", "1", "1"},
            {"rotate_x", "45"},
            {"rotate_y", "45"},
            {"rotate_z", "45"},
            {"translate", "-1", "-1", "-1"}
        };
        while (true) {
            transform_sequence(coord, sequence);
            System.out.printf("(%f, %f, %f)\n", coord.x, coord.y, coord.z);
        }
    }
}