public class sample_0690 {
    public static void main(String[] args) {
        int initial_x = 0, initial_y = 0, initial_z = 0;
        int translation_x = 1, translation_y = 2, translation_z = 3;
        int recursion_depth = 5;
        int[] result = transform_3d(initial_x, initial_y, initial_z, translation_x, translation_y, translation_z, recursion_depth);
        System.out.println("(" + result[0] + ", " + result[1] + ", " + result[2] + ")");
    }

    public static int[] transform_3d(int x, int y, int z, int a, int b, int c, int depth) {
        if (depth == 0) {
            return new int[]{x, y, z};
        } else {
            return transform_3d(x + a, y + b, z + c, a, b, c, depth - 1);
        }
    }
}