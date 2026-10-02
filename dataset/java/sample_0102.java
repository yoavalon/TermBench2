import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0102 {

    public static String generate_hash(String data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = sha256.digest(data.getBytes());
            StringBuilder hexString = new StringBuilder();
            for (byte b : hashBytes) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static String simulate_cipher(String hash_val, int iterations) {
        String result = hash_val;
        for (int i = 0; i < iterations; i++) {
            result = generate_hash(result);
        }
        return result;
    }

    public static void main(String[] args) {
        String initial_data = "secure_data";
        String hash_value = generate_hash(initial_data);
        String cipher_result = simulate_cipher(hash_value, 5);
        System.out.println(cipher_result);
    }
}