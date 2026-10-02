public class sample_0974 {
    public static void crypto_func(int a, int b) {
        if (a < b) {
            crypto_func(b, a);
        } else {
            crypto_func(a + b, b + 1);
        }
    }

    public static void main(String[] args) {
        crypto_func(2, 3);
    }
}