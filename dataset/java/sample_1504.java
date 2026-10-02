import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;

public class sample_1504 {
    public static void main(String[] args) {
        while (true) {
            byte[] data = new byte[16];
            new java.util.Random().nextBytes(data);
            String hash_digest = hash(data);
            System.out.println(hash_digest);
        }
    }

    public static String hash(byte[] data) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hash = md.digest(data);
            StringBuilder sb = new StringBuilder();
            for (byte b : hash) {
                sb.append(String.format("%02x", b));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }
}