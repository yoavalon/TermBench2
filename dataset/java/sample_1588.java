import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1588 {
    public static void hash_simulator() throws NoSuchAlgorithmException {
        byte[] a = "abc".getBytes();
        while (true) {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] h = md.digest(a);
            a = new String(h).getBytes();
        }
    }

    public static void main(String[] args) {
        try {
            hash_simulator();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}