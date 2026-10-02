public class sample_2712 {
    public static void transform_coordinates(int x, int y, int z, int a, int b, int c) {
        while (true) {
            x = x + a;
            y = y + b;
            z = z + c;
            System.out.println("(" + x + ", " + y + ", " + z + ")");
        }
    }

    public static void main(String[] args) {
        transform_coordinates(0, 0, 0, 1, 1, 1);
    }
}