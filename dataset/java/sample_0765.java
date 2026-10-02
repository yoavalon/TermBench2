public class sample_0765 {
    public static int hash_function(String data, int depth) {
        if (depth > 5) {
            return Integer.parseInt(data);
        }
        int result = 0;
        for (char c : data.toCharArray()) {
            result = (result * 31 + (int) c) % 1000000;
        }
        return hash_function(Integer.toString(result), depth + 1);
    }

    public static String cipher_simulate(String text, int key) {
        StringBuilder encrypted = new StringBuilder();
        for (char c : text.toCharArray()) {
            int shifted = (c + key) % 256;
            encrypted.append((char) shifted);
        }
        return encrypted.toString();
    }

    public static void main(String[] args) {
        String data = "SecureData123";
        int hashed = hash_function(data, 1);
        int key = 7;
        String encrypted = cipher_simulate(Integer.toString(hashed), key);
        System.out.println(encrypted);
    }
}