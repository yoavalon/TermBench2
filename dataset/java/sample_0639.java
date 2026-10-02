public class sample_0639 {
    public static void main(String[] args) {
        cipher_simulate('Hello, World!', 3);
    }

    public static int hash_func(String data, int depth) {
        if (depth == 0) {
            return data.hashCode();
        } else {
            return hash_func(Integer.toString(data.hashCode()), depth - 1);
        }
    }

    public static int cipher_simulate(String data, int depth) {
        return hash_func(data, depth);
    }
}