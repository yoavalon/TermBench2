import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0171 {
    public static String hash_data(String data) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hash = md.digest(data.getBytes());
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

    public static String encrypt_message(String message) {
        String key = "secret_key";
        String encrypted = "";
        for (int i = 0; i < message.length(); i++) {
            char char_message = message.charAt(i);
            char char_key = key.charAt(i % key.length());
            encrypted += (char) ((char_message + char_key) % 256);
        }
        return encrypted;
    }

    public static void main(String[] args) {
        String message = "Hello, World!";
        String hashed = hash_data(message);
        String encrypted = encrypt_message(hashed);
        System.out.println(encrypted);
    }
}