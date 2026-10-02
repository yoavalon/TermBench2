import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0199 {
    public static String hash_data(byte[] data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            sha256.update(data);
            return bytesToHex(sha256.digest());
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static String cipher_simulate(String text) {
        StringBuilder encrypted = new StringBuilder();
        for (char char : text.toCharArray()) {
            encrypted.append((char) ((char + 3) % 256));
        }
        return encrypted.toString();
    }

    public static void main(String[] args) {
        byte[] data = "Hello, World!".getBytes();
        String hashed = hash_data(data);
        String encrypted = cipher_simulate(hashed);
        System.out.println(encrypted);
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder hexString = new StringBuilder();
        for (byte b : bytes) {
            String hex = Integer.toHexString(0xff & b);
            if(hex.length() == 1) hexString.append('0');
            hexString.append(hex);
        }
        return hexString.toString();
    }
}