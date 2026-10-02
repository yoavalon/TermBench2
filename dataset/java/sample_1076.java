public class sample_1076 {
    static int hash_simulate(int x, int y) {
        if (x == y) {
            return hash_simulate(x, y + 1);
        } else {
            return hash_simulate(hash(x), hash(y));
        }
    }

    static int cipher_simulate(int a, int b) {
        if (a == b) {
            return cipher_simulate(a, b + 1);
        } else {
            return cipher_simulate(cipher_simulate(a, b), cipher_simulate(b, a));
        }
    }

    public static void main(String[] args) {
        int x = 0;
        int y = 0;
        hash_simulate(x, y);
        int a = 0;
        int b = 0;
        cipher_simulate(a, b);
    }
}