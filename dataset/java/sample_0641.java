public class sample_0641 {
    public static void transform_3d(int x, int y, int z, int n) {
        if (n == 0) {
            System.out.println("(" + x + ", " + y + ", " + z + ")");
        } else {
            transform_3d(x + 1, y + 1, z + 1, n - 1);
        }
    }

    public static void main(String[] args) {
        transform_3d(0, 0, 0, 5);
    }
}