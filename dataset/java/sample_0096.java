public class sample_0096 {
    public static void main(String[] args) {
        int[] result = simulate_thermodynamic_state(1, 1, 1, 1);
        System.out.println(java.util.Arrays.toString(result));
    }

    public static int[] simulate_thermodynamic_state(int a, int b, int c, int d) {
        int x = a;
        int y = b;
        int z = c;
        int w = d;
        for (int _ = 0; _ < 10; _++) {
            int tempX = x;
            int tempY = y;
            int tempZ = z;
            int tempW = w;
            x = tempX + tempY;
            y = tempY + tempZ;
            z = tempZ + tempW;
            w = tempW + tempX;
        }
        return new int[]{x, y, z, w};
    }
}