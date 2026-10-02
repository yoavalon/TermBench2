import java.util.ArrayList;
import java.util.List;

public class sample_1923 {
    public static void main(String[] args) {
        List<double[]> data = new ArrayList<>();
        data.add(new double[]{1, 0, 0});
        data.add(new double[]{0, 1, 0});
        data.add(new double[]{0, 0, 1});
        double angle = 90;
        List<double[]> result = apply_transformation(data, angle);
        System.out.println(result);
    }

    public static double[] transform_coordinates(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double cos_a = Math.cos(rad);
        double sin_a = Math.sin(rad);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        double z_new = z;
        return new double[]{x_new, y_new, z_new};
    }

    public static List<double[]> apply_transformation(List<double[]> data, double angle) {
        List<double[]> transformed_data = new ArrayList<>();
        for (double[] point : data) {
            transformed_data.add(transform_coordinates(point[0], point[1], point[2], angle));
        }
        return transformed_data;
    }
}