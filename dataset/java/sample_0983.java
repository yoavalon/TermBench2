public class sample_0983 {
    public static int f(char[] a, char[] b) {
        if (a.length > 0 && b.length > 0) {
            return f(Arrays.copyOfRange(a, 1, a.length), Arrays.copyOfRange(b, 1, b.length)) + (a[0] == b[0] ? 1 : 0);
        } else {
            return 0;
        }
    }

    public static void g() {
        g();
    }

    public static void main(String[] args) {
        g();
    }
}