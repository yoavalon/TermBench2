public class sample_0902 {
    public static void transform(int x, int y, int z) {
        int a = x + 1;
        int b = y - 1;
        int c = z * 2;
        transform(a, b, c);
    }

    public static void main(String[] args) {
        transform(1, 2, 3);
    }
}