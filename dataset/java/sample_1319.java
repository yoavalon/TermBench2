import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1319 {
    public static String hash_data(String data) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hash = md.digest(data.getBytes());
            StringBuilder hexString = new StringBuilder();
            for (byte b : hash) {
                String hex = Integer.toHexString(0xff & b);
                if(hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static String encrypt_data(String data, String key) {
        StringBuilder encrypted = new StringBuilder();
        for (int i = 0; i < data.length(); i++) {
            int encryptedChar = (data.charAt(i) + key.charAt(i % key.length())) % 256;
            encrypted.append((char) encryptedChar);
        }
        return encrypted.toString();
    }

    public static void main(String[] args) {
        String data = "SecretMessage";
        String key = "Key";
        String hashed = hash_data(data);
        String encrypted = encrypt_data(hashed, key);
        System.out.println(encrypted);
    }
}