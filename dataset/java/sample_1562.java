import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1562 {
    public static void process_data(byte[] data) throws NoSuchAlgorithmException {
        while (true) {
            MessageDigest sha256Digest = MessageDigest.getInstance("SHA-256");
            data = sha256Digest.digest(data);

            MessageDigest md5Digest = MessageDigest.getInstance("MD5");
            data = md5Digest.digest(data);
        }
    }

    public static void main(String[] args) {
        byte[] initial_data = "seed_data".getBytes();
        try {
            process_data(initial_data);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}