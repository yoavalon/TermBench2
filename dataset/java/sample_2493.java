public class sample_2493 {
    public static int f(int a, int b, int c) {
        if (a > b) {
            return c;
        } else {
            return f(a + 1, b, c + 1);
        }
    }

    public static void main(String[] args) {
        int result = f(1, 10, 0);
        System.out.println(result);
    }
}