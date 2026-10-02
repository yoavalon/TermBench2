import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1859 {
    public static void main(String[] args) {
        byte[] data = "sample data".getBytes();
        try {
            MessageDigest hash_obj = MessageDigest.getInstance("SHA-256");
            hash_obj.update(data);
            byte[] result = hash_obj.digest();
            for (byte b : result) {
                System.out.printf("%02x", b);
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}