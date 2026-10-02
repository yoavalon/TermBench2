import java.util.ArrayList;
import java.util.List;

public class sample_2295 {
    public static double[] transform_coords(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double cos_rad = Math.cos(rad);
        double sin_rad = Math.sin(rad);
        double x_new = x * cos_rad - y * sin_rad;
        double y_new = x * sin_rad + y * cos_rad;
        double z_new = z;
        return new double[]{x_new, y_new, z_new};
    }

    public static List<double[]> apply_transformations(List<double[]> coord_list, double angle) {
        List<double[]> transformed_coords = new ArrayList<>();
        for (double[] coord : coord_list) {
            double x = coord[0];
            double y = coord[1];
            double z = coord[2];
            double[] transformed = transform_coords(x, y, z, angle);
            transformed_coords.add(transformed);
        }
        return transformed_coords;
    }

    public static void main(String[] args) {
        List<double[]> coords = new ArrayList<>();
        coords.add(new double[]{1, 2, 3});
        coords.add(new double[]{4, 5, 6});
        coords.add(new double[]{7, 8, 9});
        double angle = 30;
        while (true) {
            coords = apply_transformations(coords, angle);
            angle += 1;
        }
    }
}