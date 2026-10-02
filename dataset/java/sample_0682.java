public class sample_0682 {
    public static void main(String[] args) {
        recursive_filter(new int[]{1, 2, 3, 4, 5}, 3);
    }

    public static int[] recursive_filter(int[] x, int n) {
        if (n == 0) {
            return x;
        } else {
            int[] newX = new int[x.length];
            System.arraycopy(x, 1, newX, 0, x.length - 1);
            newX[x.length - 1] = 0;
            return recursive_filter(newX, n - 1);
        }
    }
}