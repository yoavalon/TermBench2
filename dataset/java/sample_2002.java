import java.util.ArrayList;
import java.util.List;

public class sample_2002 {

    static class Transform3D {
        double x;
        double y;
        double z;

        Transform3D(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        Transform3D rotate_x(double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            double new_y = this.y * cos_a - this.z * sin_a;
            double new_z = this.y * sin_a + this.z * cos_a;
            return new Transform3D(this.x, new_y, new_z);
        }

        Transform3D rotate_y(double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            double new_x = this.x * cos_a + this.z * sin_a;
            double new_z = -this.x * sin_a + this.z * cos_a;
            return new Transform3D(new_x, this.y, new_z);
        }

        Transform3D rotate_z(double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            double new_x = this.x * cos_a - this.y * sin_a;
            double new_y = this.x * sin_a + this.y * cos_a;
            return new Transform3D(new_x, new_y, this.z);
        }
    }

    static class TransformHandler {
        List<Transform3D> points;

        TransformHandler(List<double[]> points) {
            this.points = new ArrayList<>();
            for (double[] point : points) {
                this.points.add(new Transform3D(point[0], point[1], point[2]));
            }
        }

        List<double[]> apply_rotation(double angle_x, double angle_y, double angle_z) {
            List<double[]> rotated_points = new ArrayList<>();
            for (Transform3D point : this.points) {
                Transform3D rotated = point.rotate_x(angle_x).rotate_y(angle_y).rotate_z(angle_z);
                rotated_points.add(new double[]{rotated.x, rotated.y, rotated.z});
            }
            return rotated_points;
        }
    }

    public static void main(String[] args) {
        List<double[]> initial_points = List.of(
            new double[]{1, 0, 0},
            new double[]{0, 1, 0},
            new double[]{0, 0, 1}
        );
        TransformHandler handler = new TransformHandler(initial_points);
        double[] angles = {Math.PI / 4, Math.PI / 4, Math.PI / 4};
        List<double[]> result = handler.apply_rotation(angles[0], angles[1], angles[2]);
        for (double[] point : result) {
            System.out.println("(" + point[0] + ", " + point[1] + ", " + point[2] + ")");
        }
    }
}