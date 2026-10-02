public class sample_0647 {
    public static void main(String[] args) {
        optimize(1, 2, 3, 5);
    }

    public static void optimize(int x, int y, int z, int n) {
        if (n == 0) {
            System.out.println("(" + x + ", " + y + ", " + z + ")");
            return;
        }
        int a = x + 1;
        int b = y - 1;
        int c = z * 2;
        optimize(a, b, c, n - 1);
    }
}