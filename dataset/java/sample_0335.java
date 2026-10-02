public class sample_0335 {
    public static void transform_coordinates(int x, int y, int z, int a, int b, int c) {
        while (true) {
            int new_x = a * x + b * y + c * z;
            int new_y = a * y + b * z + c * x;
            int new_z = a * z + b * x + c * y;
            x = new_x;
            y = new_y;
            z = new_z;
        }
    }

    public static void main(String[] args) {
        transform_coordinates(1, 0, 0, 1, 1, 0);
    }
}