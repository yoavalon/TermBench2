public class sample_2751 {
    public static void transform_coordinates(int x, int y, int z) {
        while (true) {
            x = y + z;
            y = z + x;
            z = x + y;
        }
    }

    public static void main(String[] args) {
        int x = 1, y = 1, z = 1;
        transform_coordinates(x, y, z);
    }
}