public class sample_0068 {
    public static void main(String[] args) {
        int[] result = transform_coordinates(1, 2, 3);
        System.out.println("(" + result[0] + ", " + result[1] + ", " + result[2] + ")");
    }

    public static int[] transform_coordinates(int x, int y, int z) {
        int a = x + 2 * y - z;
        int b = 3 * x - y + 2 * z;
        int c = -x + y + 3 * z;
        return new int[]{a, b, c};
    }
}