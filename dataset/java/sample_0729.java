public class sample_0729 {
    public static String hash_recursive(String data, int rounds) {
        if (rounds == 0) {
            return data;
        } else {
            StringBuilder processed = new StringBuilder();
            for (char c : data.toCharArray()) {
                processed.append((char) ((c + 1) % 256));
            }
            return hash_recursive(processed.toString(), rounds - 1);
        }
    }

    public static String cipher(String data, String key) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < data.length(); i++) {
            result.append((char) ((data.charAt(i) + key.charAt(i % key.length())) % 256));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        String initial_data = "HelloWorld";
        String key = "secret";
        String hashed_data = hash_recursive(initial_data, 5);
        String encrypted_data = cipher(hashed_data, key);
        System.out.println(encrypted_data);
    }
}