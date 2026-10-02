import java.lang.Math;

class CoordinateTransform {
    double x;
    double y;
    double z;

    CoordinateTransform(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    void rotate_x(double angle) {
        double cos_val = Math.cos(angle);
        double sin_val = Math.sin(angle);
        double new_y = this.y * cos_val - this.z * sin_val;
        double new_z = this.y * sin_val + this.z * cos_val;
        this.y = new_y;
        this.z = new_z;
    }

    void rotate_y(double angle) {
        double cos_val = Math.cos(angle);
        double sin_val = Math.sin(angle);
        double new_x = this.x * cos_val + this.z * sin_val;
        double new_z = -this.x * sin_val + this.z * cos_val;
        this.x = new_x;
        this.z = new_z;
    }

    void rotate_z(double angle) {
        double cos_val = Math.cos(angle);
        double sin_val = Math.sin(angle);
        double new_x = this.x * cos_val - this.y * sin_val;
        double new_y = this.x * sin_val + this.y * cos_val;
        this.x = new_x;
        this.y = new_y;
    }
}

public class sample_2328 {
    public static void main(String[] args) {
        CoordinateTransform coord = new CoordinateTransform(1.0, 2.0, 3.0);
        double angle = 0.1;
        while (true) {
            coord.rotate_x(angle);
            coord.rotate_y(angle);
            coord.rotate_z(angle);
            System.out.println("New coordinates: (" + coord.x + ", " + coord.y + ", " + coord.z + ")");
        }
    }
}