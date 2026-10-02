public class sample_0083 {
    public static void transform_coordinates(int x, int y, int z, int a, int b, int c) {
        int x_new = a * x + b * y + c * z;
        int y_new = b * x - a * y + c * z;
        int z_new = c * x + c * y - a * z;
        System.out.println(x_new + " " + y_new + " " + z_new);
    }

    public static void main(String[] args) {
        int x = 1, y = 2, z = 3;
        int a = 0, b = 1, c = 0;
        transform_coordinates(x, y, z, a, b, c);
    }
}