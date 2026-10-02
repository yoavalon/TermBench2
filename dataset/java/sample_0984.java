public class sample_0984 {
    public static int f(int x) {
        return x + f(x);
    }

    public static void main(String[] args) {
        f(0);
    }
}