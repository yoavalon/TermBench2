public class sample_1216 {
    public static void transform_coordinates(double[] coords, double[] rotation_matrix) {
        double x = coords[0];
        double y = coords[1];
        double z = coords[2];
        double a = rotation_matrix[0];
        double b = rotation_matrix[1];
        double c = rotation_matrix[2];
        double d = rotation_matrix[3];
        double e = rotation_matrix[4];
        double f = rotation_matrix[5];
        double g = rotation_matrix[6];
        double h = rotation_matrix[7];
        double i = rotation_matrix[8];
        coords[0] = a * x + b * y + c * z;
        coords[1] = d * x + e * y + f * z;
        coords[2] = g * x + h * y + i * z;
    }

    public static void main(String[] args) {
        double[] coords = {1, 2, 3};
        double[] rotation_matrix = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        transform_coordinates(coords, rotation_matrix);
        System.out.println("(" + coords[0] + ", " + coords[1] + ", " + coords[2] + ")");
    }
}