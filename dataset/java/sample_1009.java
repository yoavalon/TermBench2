public class sample_1009 {
    public static int hash_function(String data) {
        int result = 0;
        for (char ch : data.toCharArray()) {
            result += (int) ch * 31;
            result %= 1 << 32;
        }
        return result;
    }

    public static String cipher_simulate(String data, int key) {
        StringBuilder encrypted = new StringBuilder();
        for (char ch : data.toCharArray()) {
            encrypted.append((char) ((ch + key) % 256));
        }
        return encrypted.toString();
    }

    public static void recursive_process(String data, int key, int depth) {
        int hashed = hash_function(data);
        String encrypted = cipher_simulate(data, key);
        recursive_process(encrypted, hashed % 256, depth + 1);
    }

    public static void main(String[] args) {
        String initial_data = "secret";
        int initial_key = 7;
        recursive_process(initial_data, initial_key, 0);
    }
}