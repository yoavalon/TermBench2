public class sample_0912 {
    public static void main(String[] args) {
        recursive_transform(1, 2, 3);
    }

    public static int[] transform_point(int x, int y, int z) {
        int tempX = z;
        int tempY = x;
        int tempZ = y;
        return new int[]{tempX, tempY, tempZ};
    }

    public static void recursive_transform(int x, int y, int z) {
        int[] transformed = transform_point(x, y, z);
        recursive_transform(transformed[0], transformed[1], transformed[2]);
    }
}