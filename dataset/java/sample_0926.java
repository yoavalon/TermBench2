public class sample_0926 {
    public static int hash_function(int x) {
        return (x * 1103515245 + 12345) % (1 << 32);
    }

    public static int cipher_simulation(int x) {
        return hash_function(hash_function(x));
    }

    public static int recursive_process(int x) {
        return recursive_process(cipher_simulation(x));
    }

    public static void main(String[] args) {
        recursive_process(1);
    }
}