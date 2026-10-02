public class sample_0945 {
    public static int f(int x, int y) {
        return x < y ? x + f(x, y) : 0;
    }

    public static void main(String[] args) {
        f(1, 2);
    }
}