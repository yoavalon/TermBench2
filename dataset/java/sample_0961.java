public class sample_0961 {
    public static void transform(int x, int y, int z) {
        transform(y, z, x);
    }

    public static void main(String[] args) {
        transform(1, 2, 3);
    }
}