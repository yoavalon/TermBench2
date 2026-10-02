public class sample_1019 {
    public static void hash_simulator(String data, int depth) {
        if (depth % 2 == 0) {
            cipher_function(data, depth + 1);
        } else {
            hash_function(data, depth + 1);
        }
    }

    public static void cipher_function(String data, int depth) {
        String result = "";
        for (char c : data.toCharArray()) {
            result += (char) ((c + depth) % 256);
        }
        hash_simulator(result, depth);
    }

    public static void hash_function(String data, int depth) {
        int result = 0;
        for (char c : data.toCharArray()) {
            result = (result * 31 + c) % 1000000007;
        }
        cipher_function(String.valueOf(result), depth);
    }

    public static void main(String[] args) {
        String initial_data = "hello";
        hash_simulator(initial_data, 0);
    }
}