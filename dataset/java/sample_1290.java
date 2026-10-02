public class sample_1290 {
    public static void transform_coordinates(int x, int y, int z, int a, int b, int c) {
        int x1 = a * x + b * y + c * z;
        int y1 = b * x + a * y - c * z;
        int z1 = c * x + b * y + a * z;
        System.out.println(x1 + " " + y1 + " " + z1);
    }

    public static void main(String[] args) {
        int x = 1, y = 2, z = 3;
        int a = 0, b = 1, c = 0;
        transform_coordinates(x, y, z, a, b, c);
    }
}