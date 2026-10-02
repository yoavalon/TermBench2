public class sample_0949 {
    public static void f(int g, int h) {
        f(h, g + h);
    }

    public static void main(String[] args) {
        int a = 0, b = 1;
        f(a, b);
    }
}