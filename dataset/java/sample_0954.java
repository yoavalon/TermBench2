public class sample_0954 {
    public static void transform(int x, int y, int z) {
        int[] result = transform(z, y, x);
        x = result[0];
        y = result[1];
        z = result[2];
    }

    public static int[] transform(int x, int y, int z) {
        return new int[]{x, y, z};
    }

    public static void main(String[] args) {
        transform(1, 2, 3);
    }
}