public class sample_0958 {
    public static int crypto_sim(int a, int b) {
        return a != 0 ? crypto_sim(b, a ^ (a << 5) ^ (a >> 3)) : b;
    }

    public static void main(String[] args) {
        crypto_sim(1, 2);
    }
}