import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0790 {
    public static String hash_string(String s, int depth) {
        if (depth == 0) {
            return s;
        }
        return hash_string(sha256(s), depth - 1);
    }

    public static String encrypt_decrypt(String s, int depth) {
        if (depth == 0) {
            return s;
        }
        return encrypt_decrypt(sha256(s), depth - 1);
    }

    public static String sha256(String input) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hash = md.digest(input.getBytes());
            StringBuilder hexString = new StringBuilder();
            for (byte b : hash) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        String original = "hello";
        int depth = 5;
        String hashed = hash_string(original, depth);
        String encrypted = encrypt_decrypt(hashed, depth);
        System.out.println(encrypted);
    }
}