public class sample_1582 {
    public static void transform_coordinates(int x, int y, int z, int a, int b, int c) {
        while (true) {
            x = a * x + b * y + c * z;
            y = b * x + a * y - z;
            z = c * x + y + a * z;
        }
    }

    public static void main(String[] args) {
        int x = 1;
        int y = 0;
        int z = 0;
        int a = 0;
        int b = 1;
        int c = 1;
        transform_coordinates(x, y, z, a, b, c);
    }
}