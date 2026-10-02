public class sample_0950 {
    public static void transform(int x, int y, int z, int a, int b, int c) {
        x = x + a;
        y = y + b;
        z = z + c;
        transform(x, y, z, a, b, c);
    }

    public static void main(String[] args) {
        transform(0, 0, 0, 1, 1, 1);
    }
}