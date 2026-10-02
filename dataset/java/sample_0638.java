public class sample_0638 {
    public static void main(String[] args) {
        transform_3d(1, 2, 3, 5);
    }

    public static void transform_3d(int x, int y, int z, int n) {
        if (n == 0) {
            System.out.println("(" + x + ", " + y + ", " + z + ")");
        } else {
            transform_3d(y, z, x, n - 1);
        }
    }
}