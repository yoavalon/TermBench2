import java.util.ArrayList;
import java.util.List;

class Transformation {
    double angle;
    double scale;

    Transformation(double angle, double scale) {
        this.angle = angle;
        this.scale = scale;
    }

    double[] rotate(double[] point) {
        double x = point[0];
        double y = point[1];
        double z = point[2];
        double cos_theta = Math.cos(angle);
        double sin_theta = Math.sin(angle);
        double x_new = x * cos_theta - y * sin_theta;
        double y_new = x * sin_theta + y * cos_theta;
        double z_new = z;
        return new double[]{x_new, y_new, z_new};
    }

    double[] scale_point(double[] point) {
        double x = point[0];
        double y = point[1];
        double z = point[2];
        return new double[]{x * scale, y * scale, z * scale};
    }
}

public class sample_0573 {
    static List<double[]> apply_transformations(List<double[]> points, List<Transformation> transformations) {
        List<double[]> transformed_points = new ArrayList<>();
        for (double[] point : points) {
            for (Transformation transformation : transformations) {
                point = transformation.rotate(point);
                point = transformation.scale_point(point);
            }
            transformed_points.add(point);
        }
        return transformed_points;
    }

    static void process_data() {
        List<double[]> points = new ArrayList<>();
        points.add(new double[]{1, 0, 0});
        points.add(new double[]{0, 1, 0});
        points.add(new double[]{0, 0, 1});
        List<Transformation> transformations = new ArrayList<>();
        transformations.add(new Transformation(Math.PI / 4, 2));
        transformations.add(new Transformation(Math.PI / 8, 3));
        while (true) {
            points = apply_transformations(points, transformations);
        }
    }

    public static void main(String[] args) {
        process_data();
    }
}