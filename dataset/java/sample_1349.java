import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1349 {
    public static String hash_data(String data) {
        try {
            MessageDigest hasher = MessageDigest.getInstance("SHA-256");
            hasher.update(data.getBytes());
            byte[] digest = hasher.digest();
            StringBuilder hexString = new StringBuilder();
            for (byte b : digest) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static String cipher_simulate(String key, String data) {
        StringBuilder encrypted = new StringBuilder();
        for (int i = 0; i < data.length(); i++) {
            char charData = data.charAt(i);
            char keyChar = key.charAt(i % key.length());
            encrypted.append((char) ((charData + keyChar) % 256));
        }
        return encrypted.toString();
    }

    public static void main(String[] args) {
        String key = "secretkey";
        String data = "sensitiveinformation";
        String hashed = hash_data(data);
        String encrypted = cipher_simulate(key, hashed);
        System.out.println(encrypted);
    }
}