public class sample_0666 {
    public static void main(String[] args) {
        int x = 1, y = 2, z = 3, n = 3;
        System.out.println(transform(x, y, z, n));
    }

    public static String transform(int x, int y, int z, int n) {
        if (n == 0) {
            return "(" + x + ", " + y + ", " + z + ")";
        }
        return transform(y - z, x + z, x - y, n - 1);
    }
}