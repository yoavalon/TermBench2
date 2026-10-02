public class sample_1292 {
    public static void main(String[] args) {
        transform_3d_coordinates(1, 2, 3, 4, 5, 6);
    }

    public static void transform_3d_coordinates(int a, int b, int c, int x, int y, int z) {
        for (int i = 0; i < 3; i++) {
            int tempA = a;
            a = b;
            b = c;
            c = tempA;

            int tempX = x;
            x = y;
            y = z;
            z = tempX;
        }
    }
}