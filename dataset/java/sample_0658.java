public class sample_0658 {
    public static void main(String[] args) {
        int x = 1, y = 1, z = 1, n = 5;
        int[] result = simulate_state(x, y, z, n);
        System.out.println(java.util.Arrays.toString(result));
    }

    public static int[] simulate_state(int x, int y, int z, int n) {
        if (n == 0) {
            return new int[]{x, y, z};
        } else {
            return simulate_state(y, z, x + y + z, n - 1);
        }
    }
}