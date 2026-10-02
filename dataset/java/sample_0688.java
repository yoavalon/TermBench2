public class sample_0688 {
    public static int a(int b, int c, int d) {
        if (b <= 0 || c <= 0 || d <= 0) {
            return 0;
        }
        if (b == 1 && c == 1 && d == 1) {
            return 1;
        }
        return a(b - 1, c, d) + a(b, c - 1, d) + a(b, c, d - 1);
    }

    public static void main(String[] args) {
        System.out.println(a(3, 3, 3));
    }
}