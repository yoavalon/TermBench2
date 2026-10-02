public class sample_0667 {
    public static void transform_point(int x, int y, int z, int depth) {
        if (depth == 0) {
            System.out.println("(" + x + ", " + y + ", " + z + ")");
        } else {
            transform_point(x + 1, y - 1, z * 2, depth - 1);
        }
    }

    public static void main(String[] args) {
        transform_point(0, 0, 0, 5);
    }
}