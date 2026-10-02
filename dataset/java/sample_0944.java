public class sample_0944 {
    public static void transform(int x, int y, int z) {
        transform(z, x, y);
    }

    public static void main(String[] args) {
        transform(1, 2, 3);
    }
}