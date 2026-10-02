public class sample_0035 {
    public static void main(String[] args) {
        transform_coordinates(1, 2, 3, 0, 1, 0);
    }

    public static void transform_coordinates(int x, int y, int z, int a, int b, int c) {
        int x_new = a * x + b * y + c * z;
        int y_new = b * x + a * y - c * z;
        int z_new = c * x + b * y + a * z;
    }
}