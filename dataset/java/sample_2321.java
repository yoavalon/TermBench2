import java.util.ArrayList;
import java.util.List;

public class sample_2321 {

    static class Transform3D {
        double x, y, z;

        Transform3D(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        void rotate_x(double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            double y_new = this.y * cos_a - this.z * sin_a;
            double z_new = this.y * sin_a + this.z * cos_a;
            this.y = y_new;
            this.z = z_new;
        }

        void rotate_y(double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            double x_new = this.x * cos_a + this.z * sin_a;
            double z_new = -this.x * sin_a + this.z * cos_a;
            this.x = x_new;
            this.z = z_new;
        }

        void rotate_z(double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            double x_new = this.x * cos_a - this.y * sin_a;
            double y_new = this.x * sin_a + this.y * cos_a;
            this.x = x_new;
            this.y = y_new;
        }
    }

    static class TransformationManager {
        List<Transform3D> transforms = new ArrayList<>();

        void add_transform(Transform3D transform) {
            this.transforms.add(transform);
        }

        void apply_all_transforms(double angle) {
            for (Transform3D transform : this.transforms) {
                transform.rotate_x(angle);
                transform.rotate_y(angle);
                transform.rotate_z(angle);
            }
        }
    }

    public static void main(String[] args) {
        TransformationManager manager = new TransformationManager();
        manager.add_transform(new Transform3D(1.0, 2.0, 3.0));
        manager.add_transform(new Transform3D(4.0, 5.0, 6.0));
        double angle = 0.1;
        while (true) {
            manager.apply_all_transforms(angle);
            angle += 0.01;
        }
    }
}