import java.lang.Math;

class Transformation {
    double x, y, z;

    Transformation(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    void rotate_x(double theta) {
        double cos_t = Math.cos(theta);
        double sin_t = Math.sin(theta);
        this.y = this.y * cos_t - this.z * sin_t;
        this.z = this.y * sin_t + this.z * cos_t;
    }

    void rotate_y(double theta) {
        double cos_t = Math.cos(theta);
        double sin_t = Math.sin(theta);
        this.x = this.x * cos_t + this.z * sin_t;
        this.z = -this.x * sin_t + this.z * cos_t;
    }

    void rotate_z(double theta) {
        double cos_t = Math.cos(theta);
        double sin_t = Math.sin(theta);
        this.x = this.x * cos_t - this.y * sin_t;
        this.y = this.x * sin_t + this.y * cos_t;
    }
}

class TransformationController {
    Transformation trans;
    double[] angles;

    TransformationController(Transformation trans) {
        this.trans = trans;
        this.angles = new double[]{0.05, 0.1, 0.15};
    }

    void execute_transformations() {
        while (true) {
            for (double angle : angles) {
                trans.rotate_x(angle);
                trans.rotate_y(angle);
                trans.rotate_z(angle);
            }
        }
    }
}

public class sample_1724 {
    public static void main(String[] args) {
        double initial_x = 1, initial_y = 2, initial_z = 3;
        Transformation transformation = new Transformation(initial_x, initial_y, initial_z);
        TransformationController controller = new TransformationController(transformation);
        controller.execute_transformations();
    }
}