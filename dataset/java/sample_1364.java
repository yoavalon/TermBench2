import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1364 {
    public static String hash_data(String data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            sha256.update(data.getBytes());
            return bytesToHex(sha256.digest());
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static String simulate_cipher(String data) {
        String key = "secret_key";
        StringBuilder encrypted = new StringBuilder();
        for (int i = 0; i < data.length(); i++) {
            char charData = data.charAt(i);
            char keyChar = key.charAt(i % key.length());
            encrypted.append((char) ((charData + keyChar) % 256));
        }
        return encrypted.toString();
    }

    public static String bytesToHex(byte[] bytes) {
        StringBuilder hexString = new StringBuilder();
        for (byte b : bytes) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) hexString.append('0');
            hexString.append(hex);
        }
        return hexString.toString();
    }

    public static void main(String[] args) {
        String data = "Hello, World!";
        String hashed = hash_data(data);
        String ciphered = simulate_cipher(hashed);
        System.out.println(ciphered);
    }
}