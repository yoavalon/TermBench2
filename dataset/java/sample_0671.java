public class sample_0671 {
    public static String crypto_hash(String data, int depth) {
        if (depth == 0) {
            return data;
        } else {
            return crypto_hash(new StringBuilder(data).reverse().toString(), depth - 1);
        }
    }

    public static void main(String[] args) {
        String initial_data = "securedata";
        int depth = 5;
        String result = crypto_hash(initial_data, depth);
        System.out.println(result);
    }
}