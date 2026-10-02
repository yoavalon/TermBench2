public class sample_0627 {
    public static void main(String[] args) {
        int x = 0;
        int y = 0;
        int z = 0;
        int depth = 5;
        int[] result = transform_3d(x, y, z, depth);
        System.out.println("(" + result[0] + ", " + result[1] + ", " + result[2] + ")");
    }

    public static int[] transform_3d(int x, int y, int z, int depth) {
        if (depth == 0) {
            return new int[]{x, y, z};
        }
        return transform_3d(x + 1, y + 1, z + 1, depth - 1);
    }
}