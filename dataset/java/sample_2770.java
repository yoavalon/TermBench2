import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2770 {
    public static void simulate_cipher() throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] a = "seed".getBytes();
        while (true) {
            a = md.digest(a);
        }
    }

    public static void main(String[] args) {
        try {
            simulate_cipher();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}