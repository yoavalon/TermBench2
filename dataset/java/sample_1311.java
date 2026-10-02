import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1311 {
    public static String hash_data(byte[] data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            sha256.update(data);
            return bytesToHex(sha256.digest());
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static String simulate_cipher(String data) {
        StringBuilder encrypted = new StringBuilder();
        for (char c : data.toCharArray()) {
            encrypted.append((char) ((c + 3) % 256));
        }
        return encrypted.toString();
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder hexString = new StringBuilder();
        for (byte b : bytes) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) hexString.append('0');
            hexString.append(hex);
        }
        return hexString.toString();
    }

    public static void main(String[] args) {
        byte[] data = "Sample data for hashing and cipher simulation".getBytes();
        String hashed = hash_data(data);
        String encrypted = simulate_cipher(hashed);
        System.out.println(encrypted);
    }
}