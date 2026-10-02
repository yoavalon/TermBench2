public class sample_0082 {
    public static void main(String[] args) {
        int x = 1, y = 2, z = 3;
        int a = 2, b = 3, c = 4;
        int[] result = transform_coordinates(x, y, z, a, b, c);
        System.out.println(java.util.Arrays.toString(result));
    }

    public static int[] transform_coordinates(int x, int y, int z, int a, int b, int c) {
        int x_new = x * a;
        int y_new = y * b;
        int z_new = z * c;
        return new int[]{x_new, y_new, z_new};
    }
}