public class sample_0340 {
    public static void transform_coordinates(int x, int y, int z) {
        while (true) {
            int tempX = z + y;
            int tempY = x + z;
            int tempZ = y + x;
            x = tempX;
            y = tempY;
            z = tempZ;
        }
    }

    public static void main(String[] args) {
        transform_coordinates(1, 1, 1);
    }
}