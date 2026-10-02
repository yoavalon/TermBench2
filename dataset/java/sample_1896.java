import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1896 {
    public static byte[] process_data(byte[] data) {
        try {
            MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
            hash_object.update(data);
            byte[] hash_digest = hash_object.digest();
            byte[] result = new byte[16];
            System.arraycopy(hash_digest, 0, result, 0, 16);
            return result;
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        byte[] data = "Sample data for cryptographic hashing".getBytes();
        byte[] result = process_data(data);
        for (byte b : result) {
            System.out.printf("%02x", b);
        }
    }
}