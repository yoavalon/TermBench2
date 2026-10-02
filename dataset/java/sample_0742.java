public class sample_0742 {
    public static String hash_function(String data, int rounds) {
        if (rounds == 0) {
            return data;
        } else {
            String result = "";
            for (int i = 0; i < data.length(); i++) {
                result += (char) ((data.charAt(i) + rounds) % 256);
            }
            return hash_function(result, rounds - 1);
        }
    }

    public static String cipher_encrypt(String data, int rounds) {
        if (rounds == 0) {
            return data;
        } else {
            String encrypted = "";
            for (char charData : data.toCharArray()) {
                encrypted += (char) ((charData * rounds) % 256);
            }
            return cipher_encrypt(encrypted, rounds - 1);
        }
    }

    public static void main(String[] args) {
        String initial_data = "Hello";
        String hashed_data = hash_function(initial_data, 3);
        String encrypted_data = cipher_encrypt(hashed_data, 2);
        System.out.println(encrypted_data);
    }
}