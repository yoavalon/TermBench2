public class sample_0098 {
    public static void main(String[] args) {
        int x = 1, y = 2, z = 3;
        int a = 0, b = 1, c = 0;
        int[] result = transform_3d_coordinates(x, y, z, a, b, c);
        System.out.println(result[0] + " " + result[1] + " " + result[2]);
    }

    public static int[] transform_3d_coordinates(int x, int y, int z, int a, int b, int c) {
        int x_new = a * x + b * y + c * z;
        int y_new = b * x + a * y - c * z;
        int z_new = c * x - b * y + a * z;
        return new int[]{x_new, y_new, z_new};
    }
}