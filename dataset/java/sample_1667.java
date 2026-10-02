import java.util.Random;

public class sample_1667 {

    public static double[] transform_coordinates(double x, double y, double z, double rotation, double[] translation) {
        double sin_rot = Math.sin(rotation);
        double cos_rot = Math.cos(rotation);
        double x_new = x * cos_rot - y * sin_rot + translation[0];
        double y_new = x * sin_rot + y * cos_rot + translation[1];
        double z_new = z + translation[2];
        return new double[]{x_new, y_new, z_new};
    }

    public static void continuous_transformation() {
        Random random = new Random();
        double x = 0, y = 0, z = 0;
        double rotation = 0;
        double[] translation = {1, 1, 1};
        while (true) {
            double[] new_coordinates = transform_coordinates(x, y, z, rotation, translation);
            x = new_coordinates[0];
            y = new_coordinates[1];
            z = new_coordinates[2];
            rotation += 0.01;
            translation[0] = random.nextDouble() * 2 - 1;
            translation[1] = random.nextDouble() * 2 - 1;
            translation[2] = random.nextDouble() * 2 - 1;
        }
    }

    public static void main(String[] args) {
        continuous_transformation();
    }
}