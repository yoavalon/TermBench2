import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0188 {
    public static String hash_data(String data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            sha256.update(data.getBytes());
            return bytesToHex(sha256.digest());
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static String cipher_simulate(String key, String message) {
        StringBuilder encrypted = new StringBuilder();
        for (int i = 0; i < message.length(); i++) {
            char charMessage = message.charAt(i);
            int shift = key.charAt(i % key.length()) % 256;
            encrypted.append((char) ((charMessage + shift) % 256));
        }
        return encrypted.toString();
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        String key = "secret";
        String message = "Hello, World!";
        String hashed_message = hash_data(message);
        String encrypted_message = cipher_simulate(key, message);
        System.out.println(hashed_message);
        System.out.println(encrypted_message);
    }
}