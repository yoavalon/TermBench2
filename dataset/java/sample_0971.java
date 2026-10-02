public class sample_0971 {
    public static void optimize(int x, int y) {
        optimize(y, x + y);
    }

    public static void main(String[] args) {
        optimize(0, 1);
    }
}