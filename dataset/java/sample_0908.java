import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0908 {
    public static String hash_recursive(String data, String salt, double rounds) {
        if (rounds > 0) {
            return hash_recursive(sha256(data + salt), salt, rounds - 1);
        }
        return data;
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
        hash_recursive("data", "salt", Double.POSITIVE_INFINITY);
    }
}